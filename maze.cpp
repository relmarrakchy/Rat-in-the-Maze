#include "maze.h"

int main(int argc, char const *argv[])
{
    maze m = createMaze();
    setBlocks(&m);
    setMark(&m);
    displayMaze(&m);
    return 0;
}