/*
  Faculty.h is the header file that declares the name variable, the level variable,
  the department variable, the numberOfAdvisees variable, the adviseeIDs variable,
  and the function names
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Faculty {
public:
  string name;
  string level;
  string department;
  int numberOfAdvisees;
  int* adviseeIDs;
  Faculty();
  Faculty(string n, string l, string d, int nOA, int* aIDs);
  ~Faculty();
  int getNumberOfAdvisees();
  void deleteAdvisee(int aID);
  void print();
  void printFile(int id, string fileName);
  istream& operator>> (istream& is);
};

/*
  Constructor for Faculty.
*/
Faculty::Faculty() {
  name = "";
  level = "";
  department = "";
  numberOfAdvisees = 0;
  adviseeIDs = new int[numberOfAdvisees];
}

/*
  Overloaded Constructor for Faculty.
  @param n: name, l: level, d: department, nOA: numberOfAdvisees, aIDs: adviseeIDs
*/
Faculty::Faculty(string n, string l, string d, int nOA, int* aIDs) {
  name = n;
  level = l;
  department = d;
  numberOfAdvisees = nOA;
  adviseeIDs = new int[nOA];
  for (int i = 0; i < numberOfAdvisees; i++) {
    adviseeIDs[i] = aIDs[i];
  }
}

/*
  Destructor for Faculty.
*/
Faculty::~Faculty() {
  return;
}
/*
  getNumberOfAdvisees
  Returns the numberOfAdvisees value
  @return advisorID
*/
int Faculty::getNumberOfAdvisees() {
  return numberOfAdvisees;
}

/*
  deleteAdvisee
  Deletes the advisee given the adviseeID
  @param aID: adviseeID
*/
void Faculty::deleteAdvisee(int aID) {
  for (int i = 0; i < numberOfAdvisees; i++) {
    if (adviseeIDs[i] == aID) {
      adviseeIDs[i] = -1;   // means that there's no student in this position
    }
  }
  numberOfAdvisees = numberOfAdvisees - 1;
}

/*
  print
  Prints each of the member variables of Faculty to the terminal
*/
void Faculty::print() {
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  cout << "Number of Advisees: " << numberOfAdvisees << endl;
  for (int i = 0; i < numberOfAdvisees; i++) {
    cout << "Advisee #" << (i + 1) << ": " << adviseeIDs[i] << endl;
  }
}

/*
  printFile
  Writes each of the member variables of Faculty a given file name and an id
  @param id: id of Faculty to write, fileName: name of the file to append to
*/
void Faculty::printFile(int id, string fileName) {
  ofstream out_File(fileName, ios::app);
  out_File << id << ": ";
  out_File << name << " ";
  out_File << level << " ";
  out_File << department << " ";
  out_File << numberOfAdvisees << " ";
  for (int i = 0; i < numberOfAdvisees; i++) {
    if (adviseeIDs[i] != -1) {
      out_File << adviseeIDs[i] << " ";
    }
  }
  out_File << endl;
  out_File.close();
}

/*
  operator overloading the ">>" symbol
  @param input: reference to an input stream object
*/
istream& Faculty::operator>>(istream& input) {
    getline(input, this->name);
    getline(input, this->level);
    getline(input, this->department);
    input >> this->numberOfAdvisees;
    for (int i = 0; i < this->numberOfAdvisees; i++) {
      input >> this->adviseeIDs[i];
    }
    input.ignore(1024, '\n');
    return input;
}
