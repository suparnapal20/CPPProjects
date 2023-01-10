/*
  Cell.h is the header file that declares the status variable, newGrid dynamic
  array, and the function names
*/
#include <iostream>

using namespace std;

class Cell {
  public:
    char status;
    char **newGrid;
    Cell(char c);
    ~Cell();
    void changeStatus();
    char statusCheck(int n);
};
