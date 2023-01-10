/*
  Cell.cpp is the class file for Cell which declares the variables and
  functions mentioned in the header file
*/
#include <iostream>
#include <string>
#include "Cell.h"

using namespace std;

/*
  Cell(char c)
  the Cell(char c) function is the constructor that takes in char c and sets
  status equal to c
  @param char c
  @return N/A
*/
Cell::Cell(char c) {
  status = c;
}

/*
  ~Cell()
  the ~Cell() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
Cell::~Cell(){
  string s = "deleted";
}

/*
  statusCheck()
  the statusCheck() function takes in a number of neighbors and changes the
  status variable accordingly
  @param int n
  @return char status
*/
char Cell::statusCheck(int n) {
  if (n <= 1) {
    status = '-';
  }
  else if (n == 2) {
    status = status;
  }
  else if (n == 3) {
    status = 'X';
  }
  else if (n >= 4){
    status = '-';
  }
  return status;
}
