#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
#define N 10
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// My very first maze (Rat in the maze)

// I represent my maze by a square matrix of degree N, my maze is simple with an ordinary blocks, the rat is represented by num 5 (randomly),
// the blocks are represented by -1 (negative number), the correct path is represented by 0 and the mark (chesse) is represented by 1.

class maze
{
private:
    int xR = 0, yR = 0; // Coord of the rat
    int xM, yM; //Coord of the mark
    int **yard; //The maze

public:
    maze(){};

    maze(int **yard)
    {
        this->yard = yard;
    }

    int **getYard()
    {
        return this->yard;
    }

    void setXMark(int x) {
        this->xM = x;
    }

    int getXMark() {
        return this->xM;
    }

    void setYMark(int y) {
        this->yM = y;
    }

    int getYMark() {
        return this->yM;
    }

    void setXRat(int x)
    {
        this->xR = x;
    }

    int getXRat()
    {
        return this->xR;
    }

    void setYRat(int y)
    {
        this->yR = y;
    }

    int getYRat()
    {
        return this->yR;
    }
};

maze createMaze();        // Setup a maze
void setBlocks(maze *);   // Set blocks (simple blocks)
void setMark(maze *);     // Set mark (represented by 1)
void displayMaze(maze *); // Display the maze
void moveRat(maze *);     // Move the rat

maze createMaze()
{
    // Create dynamacilly a square matrix of degree N
    int **yard = new int *[N];

    for (int i = 0; i < N; i++)
    {
        yard[i] = new int[N];
    }

    maze m = maze(yard);

    // full up the matrix by 0
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!i && !j)
            {
                m.getYard()[i][j] = 5;
                continue;
            }
            m.getYard()[i][j] = 0;
        }
    }

    return m;
}

void setBlocks(maze *m)
{
    // uptodown is a variable that told the process if it should setup the blocks up to down or the reverse
    int uptodown = 1;
    for (int i = 0; i < N; i++)
    {
        // the first loop is for the first row of the matrix
        for (int j = 0; j < N; j++)
        {
            // I make my blocks in the nth odd columns
            if (j % 2 && uptodown)
            {
                for (int k = 0; k < N - 1; k++)
                {
                    m->getYard()[k][j] = -1;
                }
                uptodown = 0;
            }
            else if (j % 2 && !uptodown)
            {
                for (int k = N - 1; k > 0; k--)
                {
                    m->getYard()[k][j] = -1;
                }
                uptodown = 1;
            }
        }
        break;
    }
}

void setMark(maze *m)
{
    // By the way I setup my blocks, the mark or the end of the path should in the coord(0, N - 1) or in the coord(N - 1, N - 1)
    if (!(m->getYard()[N - 1][N - 1])) {
        m->getYard()[N - 1][N - 1] = 1;
        //Save the mark coord
        m->setYMark(N - 1);
        m->setXMark(N - 1);
    } else {
        m->getYard()[0][N - 1] = 1;
        //save the mark coord
        m->setYMark(0);
        m->setXMark(N - 1);
    }
}

void displayMaze(maze *m)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (m->getYard()[i][j] == 5)
            {
                cout << "O\t";
                continue;
            }
            if (!(m->getYard()[i][j]))
            {
                cout << "\t";
                continue;
            }
            else if (m->getYard()[i][j] == 1)
            {
                cout << "X\t";
                continue;
            }
            cout << "|\t";
        }
        cout << endl;
    }
}

void moveRat(maze *m)
{
    while (1)
    {
        if (m->getXRat() == m->getXMark() && m->getYRat() == m->getYMark()) break;
        cout << endl;
        cout << "Move me ! : ";
        int c = getch();
        if (c != 224)
        {
            switch (c)
            {
            case UP:
                cout << " UP!" << endl;
                // check if the future move is correct (valid coord & is not a block)
                if (m->getYRat() - 1 < 0 || m->getYard()[m->getYRat() - 1][m->getXRat()] == -1)
                {
                    cout << "XXXXXXXX WRONG MOVE ! XXXXXXXXXX" << endl;
                    break;
                }
                m->getYard()[m->getYRat()][m->getXRat()] = 0;
                m->setYRat(m->getYRat() - 1);
                m->getYard()[m->getYRat()][m->getXRat()] = 5;
                break;
            
            case DOWN:
                cout << " DOWN!" << endl;
                // check if the future move is correct (valid coord & is not a block)
                if (m->getYRat() + 1 >= N || m->getYard()[m->getYRat() + 1][m->getXRat()] == -1)
                {
                    cout << "XXXXXXXX WRONG MOVE ! XXXXXXXXXX" << endl;
                    break;
                }
                m->getYard()[m->getYRat()][m->getXRat()] = 0;
                m->setYRat(m->getYRat() + 1);
                m->getYard()[m->getYRat()][m->getXRat()] = 5;
                break;
            
            case LEFT:
                cout << " LEFT!" << endl;
                // check if the future move is correct (valid coord & is not a block)
                if (m->getXRat() - 1 < 0 || m->getYard()[m->getYRat()][m->getXRat() - 1] == -1)
                {
                    cout << "XXXXXXXX WRONG MOVE ! XXXXXXXXXX" << endl;
                    break;
                }
                m->getYard()[m->getYRat()][m->getXRat()] = 0;
                m->setXRat(m->getXRat() - 1);
                m->getYard()[m->getYRat()][m->getXRat()] = 5;
                break;
            
            case RIGHT:
                cout << " RIGHT!" << endl;
                // check if the future move is correct (valid coord & is not a block)
                if (m->getXRat() + 1 >= N || m->getYard()[m->getYRat()][m->getXRat() + 1] == -1)
                {
                    cout << "XXXXXXXX WRONG MOVE ! XXXXXXXXXX" << endl;
                    break;
                }
                m->getYard()[m->getYRat()][m->getXRat()] = 0;
                m->setXRat(m->getXRat() + 1);
                m->getYard()[m->getYRat()][m->getXRat()] = 5;
                break;
            
            default:
                cout << "XXXXXXXX INVALID MOVE XXXXXXXXXX" << endl;
                break;
            }
            Sleep(200);
            system("cls");
            displayMaze(m);
        }
    }
    cout << endl << "YOU DID IT !";
}
