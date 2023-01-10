/*
  Output.h is the header file that declares the file and mode types, file name,
  pauseRequest, Xcounter, num, gen, and same variables and the function names
*/
#include <iostream>

using namespace std;

class Output {
  private:
    string fileType;
    string modeType;
    string fileName;
    string pauseRequest;
    string outputFile;
    int Xcounter;
    int num;
    int gen;
    int same;

  public:
    Output();
    ~Output();
    void userInput();
    void classicOutput(char **g, int rows, int cols);
    void classicOutputFile(char **g, int rows, int cols);
    void doughnutOutput(char **g, int rows, int cols);
    void doughnutOutputFile(char **g, int rows, int cols);
    void mirrorOutput(char **g, int rows, int cols);
    void mirrorOutputFile(char **g, int rows, int cols);
};
