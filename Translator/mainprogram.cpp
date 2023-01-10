/*
  mainprogram.cpp is the C++ file that contains the main function, which calls
  to declared functions from FileProcessor.h and FileProcessor.cpp
*/
#include "FileProcessor.h"
#include <iostream>

using namespace std;

/*
  main()
  this function creates a FileProcessor object and two strings for the input
  and output file names, prompts the user for the file names, and then calls
  to processFile() from FileProcessor to translate the input file and display
  it in the output file
  @param N/A
  @return int value 0
*/
int main(){
  FileProcessor f;
  string in;
  string on;

  cout << "enter input name (include .txt extension): ";
  getline(cin, in);
  cout << "enter output name (include .txt extension): ";
  getline(cin, on);
  f.processFile(in, on);
  return 0;
}
