#include <iostream>
#include <cstdlib>
using namespace std;
#define N 8

class maze {
private:
    int **yard;
public:
    maze() {};

    maze(int **yard) {
        this->yard = yard;
    }

    int **getYard() {
        return this->yard;
    }
};

maze createMaze() {
    int **yard = new int*[N];

    for (int i = 0; i < N; i++)
    {
        yard[i] = new int[N];
    }

    maze m = maze(yard);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!i && !j) {
                m.getYard()[i][j] = 5;
                continue;
            }
            m.getYard()[i][j] = 0;
        }
    }

    m.getYard()[N - 1][N - 1] = 1;
    
    return m;
}

void setBlocks (maze *m) {
    int uptodown = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j % 2 && uptodown) {
                int k;
                for (k = 0; k < N - 1; k++) {
                    m->getYard()[k][j] = -1;
                }
                // m->getYard()[k + 1][j] = 1;
                uptodown = 0;
            } else if (j % 2 && !uptodown) {
                for (int k = N - 1; k > 0; k--) {
                    m->getYard()[k][j] = -1;
                }
                // m->getYard()[0][j] = 1;
                uptodown = 1;
            }
        }
        break;
    }
}

void displayMazeNum (maze* m) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m->getYard()[i][j] == 5) {
                cout << "O\t";
                continue;
            }
            if (!(m->getYard()[i][j])) {
                cout << "\t";
                continue;
            } else if (m->getYard()[i][j] == 1) {
                cout << "X\t";
                continue;
            }
            cout << "|\t";
        }
        cout << endl;
    }
}