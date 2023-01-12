#include <iostream>
#include <cstdlib>
using namespace std;
#define N 8

//My very first maze (Rat in the maze)

//I represent my maze by a square matrix of degree N, my maze is simple with an ordinary blocks, the rat is represented by num 5 (randomly),
//the blocks are represented by -1 (negative number), the correct path is represented by 0 and the mark (chesse) is represented by 1.

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

maze createMaze(); //Setup a maze
void setBlocks(maze *); //Set blocks (simple blocks)
void setMark(maze *); //Set mark (represented by 1)
void displayMaze(maze *); //Display the maze

maze createMaze() {
    //Create dynamacilly a square matrix of degree N
    int **yard = new int*[N];

    for (int i = 0; i < N; i++)
    {
        yard[i] = new int[N];
    }

    maze m = maze(yard);

    //full up the matrix by 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!i && !j) {
                m.getYard()[i][j] = 5;
                continue;
            }
            m.getYard()[i][j] = 0;
        }
    }
    
    return m;
}

void setBlocks (maze *m) {
    //uptodown is a variable that told the process if it should setup the blocks up to down or the reverse
    int uptodown = 1;
    for (int i = 0; i < N; i++) {
        //the first loop is for the first row of the matrix
        for (int j = 0; j < N; j++) {
            //I make my blocks in the nth odd columns
            if (j % 2 && uptodown) {
                for (int k = 0; k < N - 1; k++) {
                    m->getYard()[k][j] = -1;
                }
                uptodown = 0;
            } else if (j % 2 && !uptodown) {
                for (int k = N - 1; k > 0; k--) {
                    m->getYard()[k][j] = -1;
                }
                uptodown = 1;
            }
        }
        break;
    }
}

void setMark(maze* m) {
    //By the way I setup my blocks, the mark or the end of the path should in the coord(0, N - 1) or int the coord(N - 1, N - 1)
    (!(m->getYard()[N - 1][N - 1])) ? m->getYard()[N - 1][N - 1] = 1 : m->getYard()[0][N - 1] = 1;
}

void displayMaze(maze* m) {
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