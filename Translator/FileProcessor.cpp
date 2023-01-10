/*
  FileProcessor.cpp is the class file for FileProcessor which declares the
  variables and functions mentioned in the header file
*/
#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
  FileProcessor()
  the FileProcessor() function is the constructor that sets the line variable
  to ""
  @param N/A
  @return N/A
*/
FileProcessor::FileProcessor(){
  line = "";
}

/*
  ~FileProcessor()
  the ~FileProcessor() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
FileProcessor::~FileProcessor(){
  cout << "deleted" << endl;
}

/*
  processFile()
  the processFile() function translates a given input file into tutnese and
  displays it to a given output file
  @param string inputName, string outputName
  @return N/A
*/
void FileProcessor::processFile(string inputName, string outputName) {
  ifstream in_file;
  ofstream out_file;
  Translator translator;

  in_file.open(inputName);
  out_file.open(outputName);
  while (getline(in_file, line)) {
    out_file << translator.translateEnglishSentence(line) << endl;
  }

  in_file.close();
  out_file.close();
}
