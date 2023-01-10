/*
  FileProcessor.h is the header file that declares the name and type of the line
  variable and the function names
*/
#include <string>

using namespace std;

class FileProcessor {
  private:
    string line;
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inputName, string outputName);
};
