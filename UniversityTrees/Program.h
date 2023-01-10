/*
  FileProcessor.h is the header file that declares the newLineCharacter variable,
  the userChoice variable, the response variable, the tempStudentID variable, the
  tempFacultyID varaible, the tempAdvisorID variable, the tempNumberOfAdvisees
  variable, the studentFile variable, the studentLine variable, the studentID
  variable, the studentIntID variable, the facultyFile variable, the facultyLine
  variable, the facultyID variable, the facultyIntID variable, the tempSRoot variable,
  the tempFRoot variable, the studentTable variable, the facultyTable variables,
  and the function names
*/
#include "Tree.h"
#include "Student.h"
#include "Faculty.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

class Program {
public:
  string newLineCharacter;
  int userChoice;
  string response;
  int tempStudentID;
  int tempFacultyID;
  int tempAdvisorID;
  int tempNumberOfAdvisees;
  string studentFile;
  string studentLine;
  string studentID;
  int studentIntID;
  string facultyFile;
  string facultyLine;
  string facultyID;
  int facultyIntID;
  TreeNode<Student>* tempSRoot;
  TreeNode<Faculty>* tempFRoot;
  Tree<Student> studentTable;
  Tree<Faculty> facultyTable;
  Program(string sF, string fF);
  ~Program();
  void processFile(); //initialize trees here
  void programSimulation();
  void printStudents();
  void printFaculty();
  void displayStudent(int sID);
  void displayFaculty(int fID);
  void displayAdvisor(int sID);
  void displayAdvisees(int fID);
  void addStudent(int i, string n, string l, string m, double g, int aID);
  void deleteStudent(int sID);
  void addFaculty(int i, string n, string l, string d, int nOA, int* aIDs);
  void deleteFaculty(int fID);
  void changeAdvisor(int sID, int fID);
  void removeAdvisee(int fID, int sID);
  void exitProgram();
};

/*
  Overloaded Constructor for Program.
  @param sF: student file name, fF: faculty file name
*/
Program::Program(string sF, string fF) {
  userChoice = 0;
  response = "";
  tempStudentID = 0;
  tempFacultyID = 0;
  tempAdvisorID = 0;
  tempNumberOfAdvisees = 0;
  studentFile = sF;
  studentLine = "";
  studentID = "";
  studentIntID = 0;
  facultyFile = fF;
  facultyLine = "";
  facultyID = "";
  facultyIntID = 0;
}

/*
  Destructor for Faculty.
*/
Program::~Program() {
  return;
}

/*
  processFile
  Opens the two files (student file and faculty file) in input form and checks
  to see if the files successfully opened (meaning they exist) or failed to
  open (meaning they don't exist). If the files are opened successfully, then
  the lines are read into the studentTable and facultyTable respectively. Either
  way, the programSimulation() function is called.
*/
void Program::processFile() {
  ifstream in_file1;
  in_file1.open(studentFile, ios::in);
  Student s = Student();
  ifstream in_file2;
  in_file2.open(facultyFile, ios::in);
  Faculty f = Faculty();


  if ((in_file1.fail()) && (in_file2.fail())) {
    cout << "Files don't exist. Please add students and faculty." << endl;
    programSimulation();
  }
  else {
    while (getline(in_file1, studentID, ':')) {
      studentID.erase(remove_if(studentID.begin(), studentID.end(), ::isspace), studentID.end());
      if (studentID.empty()) {
        break;
      }
      else {
        studentIntID = stoi(studentID);
        in_file1 >> s.name >> s.level >> s.major >> s.gpa >> s.advisorID;
        studentTable.insert(new TreeNode<Student> (s, studentIntID));
      }
    }

    in_file1.close();

    while (getline(in_file2, facultyID, ':')) {
      facultyID.erase(remove_if(facultyID.begin(), facultyID.end(), ::isspace), facultyID.end());
      if (facultyID.empty()){
        break;
      }
      else {
        facultyIntID = stoi(facultyID);
        in_file2 >> f.name >> f.level >> f.department >> f.numberOfAdvisees;
        for (int i = 0; i < f.numberOfAdvisees; i++){
          in_file2 >> f.adviseeIDs[i];
        }
        facultyTable.insert(new TreeNode<Faculty> (f, facultyIntID));
      }
    }

    in_file2.close();
    programSimulation();
  }
}

/*
  programSimulation
  Creates a while loop where userChoice != 14 (exit) and prompts the user with
  the menu of option. Depending on the option chosen, the user is prompted for
  various pieces of information and the respective functions are called. If the
  user enters 14, then the while loop is exited from, and the exitProgram()
  function is called.
*/
void Program::programSimulation() {
  while (userChoice != 14) {
    cout << endl;
    cout << "Menu: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)." << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)." << endl;
    cout << "3. Find and display student information given the students id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids." << endl;
    // cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << endl;
    cout << "Please enter which menu option you would like." << endl;
    cin >> userChoice;
    cout << endl;

    if (userChoice == 1) {
      printStudents();            // still need to finish this function
    }
    else if (userChoice == 2) {
      printFaculty();             // still need to finish this function
    }
    else if (userChoice == 3) {
      cout << "Please enter the student's id." << endl;
      cin >> tempStudentID;

      displayStudent(tempStudentID);
    }
    else if (userChoice == 4) {
      cout << "Please enter the faculty member's id." << endl;
      cin >> tempFacultyID;

      displayFaculty(tempFacultyID);
    }
    else if (userChoice == 5) {
      cout << "Please enter the student's id." << endl;
      cin >> tempStudentID;

      displayAdvisor(tempStudentID);
    }
    else if (userChoice == 6) {
      cout << "Please enter the faculty member's id." << endl;
      cin >> tempFacultyID;

      displayAdvisees(tempFacultyID);
    }
    else if (userChoice == 7) {
      Student s = Student();
      cout << "Please enter the new student's id." << endl;
      cin >> tempStudentID;
      cout << "Please enter the new student's name. Don't add spaces." << endl;
      cin >> s.name;
      cout << "Please enter the new student's level." << endl;
      cin >> s.level;
      cout << "Please enter the new student's major. Don't add spaces." << endl;
      cin >> s.major;
      cout << "Please enter the new student's GPA." << endl;
      cin >> s.gpa;
      cout << "Please enter the new student's advisor's id." << endl;
      cin >> s.advisorID;

      addStudent(tempStudentID, s.name, s.level, s.major, s.gpa, s.advisorID);

      cout << "Would you like to rollback (undo) the addition of this student? (Yes/No)" << endl;
      cin >> response;

      if (response == "Yes") {
        deleteStudent(tempStudentID);
      }
    }
    else if (userChoice == 8) {
      cout << "Please enter the student's id whom you'd like to remove." << endl;
      cin >> tempStudentID;

      Student s = studentTable.search(tempStudentID);

      deleteStudent(tempStudentID);

      cout << "Would you like to rollback (undo) the removal of this student? (Yes/No)" << endl;
      cin >> response;

      if (response == "Yes") {
        addStudent(tempStudentID, s.name, s.level, s.major, s.gpa, s.advisorID);
      }
    }
    else if (userChoice == 9) {
      Faculty f = Faculty();
      cout << "Please enter the new faculty member's id." << endl;
      cin >> tempFacultyID;
      cout << "Please enter the new faculty member's name." << endl;
      cin >> f.name;
      cout << "Please enter the new faculty member's level." << endl;
      cin >> f.level;
      cout << "Please enter the new faculty member's department." << endl;
      cin >> f.department;
      cout << "Please enter the new faculty member's number of advisees." << endl;
      cin >> f.numberOfAdvisees;
      for (int i = 0; i < f.getNumberOfAdvisees(); i++) {
        cout << "Please enter the new faculty member's advisee id." << endl;
        cin >> f.adviseeIDs[i];
      }

      addFaculty(tempFacultyID, f.name, f.level, f.department, f.numberOfAdvisees, f.adviseeIDs);

      cout << "Would you like to rollback (undo) the addition of this faculty member? (Yes/No)" << endl;
      cin >> response;

      if (response == "Yes") {
        deleteFaculty(tempFacultyID);
      }
    }
    else if (userChoice == 10) {
      cout << "Please enter the faculty member's id whom you'd like to remove." << endl;
      cin >> tempFacultyID;

      Faculty f = facultyTable.search(tempFacultyID);

      deleteFaculty(tempFacultyID);

      cout << "Would you like to rollback (undo) the removal of this faculty member? (Yes/No)" << endl;
      cin >> response;

      if (response == "Yes") {
        addFaculty(tempFacultyID, f.name, f.level, f.department, f.numberOfAdvisees, f.adviseeIDs);
      }
    }
    else if (userChoice == 11) {
      cout << "Please enter the student's id." << endl;
      cin >> tempStudentID;
      cout << "Please enter the student's new advisor's id." << endl;
      cin >> tempFacultyID;

      changeAdvisor(tempStudentID, tempFacultyID);
    }
    else if (userChoice == 12) {
      cout << "Please enter the faculty member's id." << endl;
      cin >> tempFacultyID;
      cout << "Please enter the faculty member's advisee's id." << endl;
      cin >> tempStudentID;

      removeAdvisee(tempFacultyID, tempStudentID);
    }
  }
  exitProgram();
}

/*
  printStudents
  Calls the inOrder function for studentTable while passing the root node to print
  all of the Student objects
  @param node: node to begin traversal
*/
void Program::printStudents() {
  studentTable.inOrder(studentTable.root);
}

/*
  printFaculty
  Calls the inOrder function for facultyTable while passing the root node to print
  all of the Faculty objects
  @param node: node to begin traversal
*/
void Program::printFaculty() {
  facultyTable.inOrder(facultyTable.root);
}

/*
  displayStudent
  Prints a Student to the terminal given the id
  @param sID: student's id
*/
void Program::displayStudent(int sID) {
  Student tempS = studentTable.search(sID);
  tempS.print();
}

/*
  displayFaculty
  Prints a Faculty to the terminal given the id
  @param fID: faculty's id
*/
void Program::displayFaculty(int fID) {
  Faculty tempF = facultyTable.search(fID);
  tempF.print();
}

/*
  displayAdvisor
  Prints a student's advisor (Faculty) to the terminal given the student's id
  @param sID: student's id
*/
void Program::displayAdvisor(int sID) {
  Student tempS = studentTable.search(sID);
  tempAdvisorID = tempS.getAdvisorID();
  Faculty tempF = facultyTable.search(tempAdvisorID);
  tempF.print();
}

/*
  displayAdvisees
  Prints a faculty's advisees (Student) to the terminal given the faculty's id
  @param fID: faculty's id
*/
void Program::displayAdvisees(int fID) {
  Faculty tempF = facultyTable.search(fID);
  tempNumberOfAdvisees = tempF.getNumberOfAdvisees();
  for (int i = 0; i < tempNumberOfAdvisees; i++) {
    tempStudentID = tempF.adviseeIDs[i];
    Student tempS = studentTable.search(tempStudentID);
    tempS.print();
  }
}

/*
  addStudent
  Inserts a Student object into the studentTable tree given values of the member
  variables of Student
  @param i: id, n: name, l: level, m: major, g: gpa, aID: advisor ID
*/
void Program::addStudent(int i, string n, string l, string m, double g, int aID) {
  Student temp(n, l, m, g, aID);
  studentTable.insert(new TreeNode<Student> (temp, i));
}

/*
  deleteStudent
  Removes a Student object from the studentTable tree given the student's id
  @param i: id
*/
void Program::deleteStudent(int i) {
  studentTable.remove(i);
}

/*
  addFaculty
  Inserts a Faculty object into the facultyTable tree given values of the member
  variables of Faculy
  @param i: id, n: name, l: level, d: department, nOA: numberOfAdvisees, aIDs: adviseeIDs
*/
void Program::addFaculty(int i, string n, string l, string d, int nOA, int* aIDs) {
  Faculty temp(n, l, d, nOA, aIDs);
  facultyTable.insert(new TreeNode<Faculty> (temp, i));
}

/*
  deleteFaculty
  Removes a Faculty object from the facultyTable tree given the faculty's id
  @param i: id
*/
void Program::deleteFaculty(int i) {
  facultyTable.remove(i);
}

/*
  changeAdvisor
  Prompts the user for the student's id and the new advisor id and updates the
  student's advisor id.
*/
void Program::changeAdvisor(int sID, int fID) {
  // int sID = 0;
  // int aID = 0;
  // // cout << "SID: " << sID << endl;
  // // cout << "AID: " << aID << endl;
  // // studentTable.search(sID).setAdvisorID(aID);
  // // int oldAID = studentTable.search(sID).getAdvisorID();
  // // if (!(facultyTable.contains(aID))) {
  // //   cout << "This faculty advisor doesn't exist. Would you like to enter a new faculty advisor ID? (Yes/No)" << endl;
  // //   cin >> response;
  // //   if (response != "Yes") {
  // //     return;
  // //   }
  // //   else {
  // //     cin >> aID;
  // //   }
  // // }
  // // // tempS.setAdvisorID(aID);
  // // Faculty oldTempF = facultyTable.search(oldAID);
  // // Faculty newTempF = facultyTable.search(aID);
  // // oldTempF.deleteAdvisee(sID);
  // // Student tempS1 = studentTable.search(sID);
  // // cout << "S1 Advisor ID: " << tempS1.getAdvisorID() << endl;
  //
  // cout << "Please enter the student's id." << endl;
  // cin >> sID;
  // cout << "Please enter the student's new advisor's id." << endl;
  // cin >> aID;
  //
  // cout << "SID: " << sID << endl;
  // cout << "AID: " << aID << endl;
  //
  // if (!(facultyTable.contains(aID))) {
  //   cout << "This faculty advisor doesn't exist. Would you like to enter a new faculty advisor ID? (Yes/No)" << endl;
  //   cin >> response;
  //   if (response != "Yes") {
  //     return;
  //   }
  //   else {
  //     cin >> aID;
  //   }
  // }
  //
  // studentTable.search(sID).setAdvisorID(aID);
  // cout << "Changed Advisor ID: " << studentTable.search(sID).getAdvisorID() << endl;
  // Faculty tempF = facultyTable.search(aID);
  // tempF.deleteAdvisee(sID);

  Student tempS = studentTable.search(sID);
  studentTable.remove(sID);

  if (!(facultyTable.contains(fID))) {
    cout << "This faculty advisor doesn't exist. Would you like to enter a new faculty advisor ID? (Yes/No)" << endl;
    cin >> response;
    if (response != "Yes") {
      return;
    }
    else {
      cin >> fID;
    }
  }

  tempS.setAdvisorID(fID);
  studentTable.insert(new TreeNode<Student> (tempS, sID));
}

/*
  removeAdvisee
  Removes an advisee from a faculty given the faculty's id and the advisee's id
  @param fID: faculty's id, sID: student's id
*/
void Program::removeAdvisee(int fID, int sID) {
  if (!(studentTable.contains(sID))) {
    cout << "This student advisee doesn't exist. Would you like to enter a new student advisee ID? (Yes/No)" << endl;
    cin >> response;
    if (response != "Yes") {
      return;
    }
    else {
      cin >> sID;
    }
  }
  Faculty tempF = facultyTable.search(fID);
  tempF.deleteAdvisee(sID);

  cout << "Please change the advisor for the student." << endl;
  cout << "Please enter the student's new advisor's id." << endl;
  cin >> fID;

}

/*
  exitProgram
  Opens the two files (student file and faculty file) and gets the roots for
  both studentTable and facultyTable. The tables call to the inOrderFile function
  to write all of the Student objects and Faculty objects into their respective
  files before closing both files.
*/
void Program::exitProgram() {
  ofstream outFile_1;
  ofstream outFile_2;
  outFile_1.open("studentTable.txt");
  outFile_2.open("facultyTable.txt");

  tempSRoot = studentTable.getRoot();
  studentTable.inOrderFile(tempSRoot, studentFile);

  tempFRoot = facultyTable.getRoot();
  facultyTable.inOrderFile(tempFRoot, facultyFile);

  outFile_1.close();
  outFile_2.close();
}
