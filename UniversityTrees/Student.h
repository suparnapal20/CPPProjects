/*
  Student.h is the header file that declares the name variable, the level variable,
  the major variable, the gpa variable, the advisorID variable, and the function names
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  string name;
  string level;
  string major;
  double gpa;
  int advisorID;
  Student();
  Student(string n, string l, string m, double g, int aID);
  ~Student();
  void setAdvisorID(int& aID);
  int getAdvisorID();
  void print();
  void printFile(int id, string fileName);
  istream& operator>> (istream& is);
};

/*
  Constructor for Student.
*/
Student::Student() {
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisorID = 0;
}

/*
  Overloaded Constructor for Student.
  @param n: name, l: level, m: major, g: gpa, aID: advisorID
*/
Student::Student(string n, string l, string m, double g, int aID) {
  name = n;
  level = l;
  major = m;
  gpa = g;
  advisorID = aID;
}

/*
  Destructor for Student.
*/
Student::~Student() {
  return;
}

/*
  setAdvisorID
  Sets the advisorID given a new advisorID
  @param aID: integer reference
*/
void Student::setAdvisorID(int& aID) {
  advisorID = aID;
}

/*
  getAdvisorID
  Returns the advisorID value
  @return advisorID
*/
int Student::getAdvisorID() {
  return advisorID;
}

/*
  print
  Prints each of the member variables of Student to the terminal
*/
void Student::print() {
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Advisor's ID: " << advisorID << endl;
}

/*
  printFile
  Writes each of the member variables of Student a given file name and an id
  @param id: id of Student to write, fileName: name of the file to append to
*/
void Student::printFile(int id, string fileName) {
  ofstream out_File(fileName, ios::app);
  out_File << id << ": ";
  out_File << name << " ";
  out_File << level << " ";
  out_File << major << " ";
  out_File << gpa << " ";
  out_File << advisorID << " ";
  out_File << endl;
  out_File.close();
}

/*
  operator overloading the ">>" symbol
  @param input: reference to an input stream object
*/
istream& Student::operator>>(istream& input) {
    getline(input, this->name);
    getline(input, this->level);
    getline(input, this->major);
    input >> this->gpa;
    input >> this->advisorID;
    input.ignore(1024, '\n');
    return input;
}
