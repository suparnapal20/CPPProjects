/*
  mainprogram.cpp is the C++ file that contains the main function, which calls
  to declared functions from Program.h
*/
#include "Program.h"
#include <iostream>
#include <string>

using namespace std;

/*
  main()
  this function takes in the number of arguments passed and creates a dynamic
  array with the arguments; inside, it creates a Program object using the last
  two arguments in the arguments array and calls to the processFile() function
  @param int argc, char **argv
  @return int 0
*/

int main(int argc, char **argv) {
  Program p(argv[argc - 2], argv[argc - 1]);
  p.processFile();
  return 0;
}
