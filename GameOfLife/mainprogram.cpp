/*
  mainprogram.cpp is the C++ file that contains the main function, which calls
  to declared functions from Output.h and Output.cpp
*/
#include <iostream>
#include <string>
#include "Output.h"

using namespace std;

/*
  main()
  this function creates an Output object and calls to the file() function
  @param N/A
  @return int value 0
*/
int main() {
  Output o;
  o.userInput();
  return 0;
}
