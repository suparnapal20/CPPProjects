/*
  Model.h is the header file that declares the name and type of the tutword
  variable and the function names
*/
#include <string>
using namespace std;

class Model {
  private:
    string tutword;
  public:
    Model();
    ~Model();
    string translateSingleCharacter(char c);
    string translateDoubleCharacter(char c);
};
