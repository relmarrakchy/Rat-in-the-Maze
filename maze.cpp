#include "maze.h"

int main(int argc, char const *argv[])
{
    maze m = createMaze();
    setBlocks(&m);
    displayMazeNum(&m);
    return 0;
}