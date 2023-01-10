/*
  Grid.cpp is the class file for Grid which declares the variables and
  functions mentioned in the header file
*/
#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"

using namespace std;

/*
  Grid()
  the Grid() function is the constructor that sets rows and cols to 0, dens
  to 0.0, and line to ""
  @param N/A
  @return N/A
*/
Grid::Grid() {
  rows = 0;
  cols = 0;
  dens = 0.0;
  line = "";
}

/*
  ~Grid()
  the ~Grid() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
Grid::~Grid() {
  string s = "deleted";
}

/*
  createRandGrid()
  the createRandGrid() function asks the user for a a number of rows, number of
  cols, and decimal density value and then randomly declares the grid
  @param N/A
  @return N/A
*/
void Grid::createRandGrid(){
  srand(time(0));

  cout<<"Enter the amount of rows: ";
  cin>>rows;
  cout<<"Enter the amount of columns: ";
  cin>>cols;
  cout<<"Please enter a decimal value greater than 0 and less than or equal to 1: ";
  cin>>dens;

  int amountX = (rows*cols)*dens;
  cout<<" "<<amountX<<endl;

  grid = new char* [rows];

  for(int i=0;i<rows;i++){
    grid[i] = new char[cols];
  }

  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      grid[i][j] = '-';
    }
  }
  int k = 0;
    while(k<amountX){
       int randRow = rand()%rows;
       int randCol = rand()%cols;
    if(grid[randRow][randCol] == '-'){
      grid[randRow][randCol] = 'X';
      ++k;
    }
  }
}

/*
  createMapGrid()
  the createMapGrid() function takes in the file input name, reads the number
  of rows and cols and the configuration, and then randomly initializes the grid
  @param string inputName
  @return N/A
*/
void Grid::createMapGrid(string inputName) {
  ifstream in_file;
  in_file.open(inputName);

  getline(in_file, line);
  rows = stoi(line);
  getline(in_file, line);
  cols = stoi(line);

  grid = new char* [rows];
  for (int i = 0; i < rows; i++) {
    grid[i] = new char[cols];
  }

  int i = 0;

  while (getline(in_file, line)) {
    for(int j = 0 ; j < cols; ++j) {
        grid[i][j] = line[j];
    }
    i++;
  }

  in_file.close();
}

/*
  printGrid()
  the printGrid() function prints the initialized grid
  @param N/A
  @return N/A
*/
void Grid::printGrid(){
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void Grid::outputGrid(string outputName) {
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

/*
  compareGrid()
  the compareGrid() function takes in two dynamic arrays of the same r (rows)
  and c (cols) and compares the values before returning true or false depending
  on if the two grids are the same
  @param char** g1, char** g2, int r, int c
  @return bool true (or false)
*/
bool Grid::compareGrid(char** g1, char** g2, int r, int c){
  int sameCounter = 0;
  int numberOfCells = r * c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (g1[i][j] == g2[i][j]) {
        sameCounter++;
      }
    }
  }

  cout << "count: "<<sameCounter << endl;


  if (sameCounter == numberOfCells) {
    return false;
  }
  else {
    return true;
  }
}

/*
  saveGrid()
  the saveGrid() function takes in a dynamic arrays and saves it to the grid
  2d array
  @param char** g1, char** g2, int r, int c
  @return bool true (or false)
*/
void Grid::saveGrid(char** g) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = g[i][j];
    }
  }
  cout << endl;
}
