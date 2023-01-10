/*
  Mirror.h is the header file that declares the count variable and the newGrid
  dynamic array and the function names
*/
#include <iostream>

using namespace std;

class Mirror {
  public:
    int count;
    char **newGrid;
    Mirror();
    ~Mirror();
    void mirrorMode(char **grid, int rows, int cols);
    void outputGrid(char **grid, int rows, int cols, string outputName);
    void printGrid(char **grid, int rows, int cols);
};
