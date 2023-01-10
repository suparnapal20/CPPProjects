/*
  Classic.cpp is the class file for Classic which declares the variables and
  functions mentioned in the header file
*/
#include "Classic.h"
#include "Cell.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
  Classic()
  the Classic() function is the constructor that sets count to 0
  @param N/A
  @return N/A
*/
Classic::Classic() {
  count = 0;
}

/*
  ~Classic()
  the ~Classic() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
Classic::~Classic() {
  string s = "deleted";
}

/*
  classicMode()
  the classicMode() function takes in a dynamic 2d array grid, the number of
  rows, and the number of columns before initializing the newGrid variable to
  update cells
  @param char **grid, int rows, int cols
  @return N/A
*/
void Classic::classicMode(char **grid, int rows, int cols) {
  int i = 0;
  int j = 0;
  count = 0;
  newGrid = new char* [rows];
  for(int i = 0; i < rows; i++){
    newGrid[i] = new char[cols];
  }
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      newGrid[i][j] = '-';
    }
  }

  if ((i == 0) && (j == 0)) {             // top left corner
    Cell c(grid[i][j]);
    if (grid[i][j + 1] == 'X') {          // right
      count++;
    }
    if (grid[i + 1][j + 1] == 'X') {      // bottom right
      count++;
    }
    if (grid[i + 1][j] == 'X') {          // bottom
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  count = 0;
  j = cols - 1;
  if ((i == 0) && (j == cols - 1)) {      // top right corner
    Cell c(grid[i][j]);
    if (grid[i + 1][j] == 'X') {          // bottom
      count++;
    }
    if (grid[i + 1][j - 1] == 'X') {     // bottom left
      count++;
    }
    if (grid[i][j - 1] == 'X') {         // left
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  count = 0;
  i = rows - 1;
  if ((i == rows - 1) && (j == cols - 1)) {   // bottom right corner
    Cell c(grid[i][j]);
    if (grid[i][j - 1] == 'X') {              // left
      count++;
    }
    if (grid[i - 1][j - 1] == 'X') {          // top left
      count++;
    }
    if (grid[i - 1][j] == 'X') {              // top
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  count = 0;
  j = 0;
  if ((i == rows - 1) && (j == 0)) {      // bottom left corner
    Cell c(grid[i][j]);
    if (grid[i - 1][j] == 'X') {         // top
      count++;
    }
    if (grid[i - 1][j + 1] == 'X') {     // top right
      count++;
    }
    if (grid[i][j + 1] == 'X') {          // right
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  for (j = 1; j < cols - 1; j++) {    // top row
    count = 0;
    i = 0;
    Cell c(grid[i][j]);
    if (grid[i][j + 1] == 'X') {          // right
      count++;
    }
    if (grid[i + 1][j + 1] == 'X') {      // bottom right
      count++;
    }
    if (grid[i + 1][j] == 'X') {          // bottom
      count++;
    }
    if (grid[i + 1][j - 1] == 'X') {     // bottom left
      count++;
    }
    if (grid[i][j - 1] == 'X') {         // left
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  for (j = 1; j < cols - 1; j++) {   // bottom row
    count = 0;
    i = rows - 1;
    Cell c(grid[i][j]);
    if (grid[i][j - 1] == 'X') {         // left
      count++;
    }
    if (grid[i - 1][j - 1] == 'X') {     // top left
      count++;
    }
    if (grid[i - 1][j] == 'X') {         // top
      count++;
    }
    if (grid[i - 1][j + 1] == 'X') {     // top right
      count++;
    }
    if (grid[i][j + 1] == 'X') {          // right
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  for (i = 1; i < rows - 1; i++) {    // left row
    count = 0;
    j = 0;
    Cell c(grid[i][j]);
    if (grid[i - 1][j] == 'X') {          // top
      count++;
    }
    if (grid[i - 1][j + 1] == 'X') {      // top right
      count++;
    }
    if (grid[i][j + 1] == 'X') {          // right
      count++;
    }
    if (grid[i + 1][j + 1] == 'X') {      // bottom right
      count++;
    }
    if (grid[i + 1][j] == 'X') {          // bottom
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  for (i = 1; i < rows - 1; i++) {    // right row
    count = 0;
    j = cols - 1;
    Cell c(grid[i][j]);
    if (grid[i + 1][j] == 'X') {          // bottom
      count++;
    }
    if (grid[i + 1][j - 1] == 'X') {     // bottom left
      count++;
    }
    if (grid[i][j - 1] == 'X') {         // left
      count++;
    }
    if (grid[i - 1][j - 1] == 'X') {     // top left
      count++;
    }
    if (grid[i - 1][j] == 'X') {         // top
      count++;
    }
    newGrid[i][j] = c.statusCheck(count);
  }

  for (i = 1; i < rows - 1; i++) {      // everything else
    for (j = 1; j < cols - 1; j++) {
      count = 0;
      Cell c(grid[i][j]);
      if (grid[i][j + 1] == 'X') {          // right
        count++;
      }
      if (grid[i + 1][j + 1] == 'X') {      // bottom right
        count++;
      }
      if (grid[i + 1][j] == 'X') {          // bottom
        count++;
      }
      if (grid[i + 1][j - 1] == 'X') {     // bottom left
        count++;
      }
      if (grid[i][j - 1] == 'X') {         // left
        count++;
      }
      if (grid[i - 1][j - 1] == 'X') {     // top left
        count++;
      }
      if (grid[i - 1][j] == 'X') {         // top
        count++;
      }
      if (grid[i - 1][j + 1] == 'X') {     // top right
        count++;
      }
      newGrid[i][j] = c.statusCheck(count);
    }
  }
}

void Classic::outputGrid(char **grid, int rows, int cols, string outputName) {
  ofstream out_file;
  out_file.open(outputName, ios::app);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out_file << grid[i][j];
    }
    out_file << endl;
  }
  out_file << endl;
  out_file.close();
}

void Classic::printGrid(char **grid, int rows, int cols){
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
