/*
  Grid.h is the header file that declares the dimensions, the grid, the density,
  the line variable, and the function names
*/
#include <iostream>
#include <string>

using namespace std;

class Grid {
  public:
    int rows;
    int cols;
    char **grid;
    float dens;
    string line;
    Grid();
    Grid(int r, int c);
    ~Grid();
    void createRandGrid();
    string readLine(string inputName, int rowNumber);
    void createMapGrid(string inputName);  // uses fileReader()
    void printGrid();
    void outputGrid(string outputName);
    bool compareGrid(char** g1, char** g2, int rows, int cols);
    void saveGrid(char** g);
};
