/*
  Output.cpp is the class file for Output which declares the variables and
  functions mentioned in the header file
*/
#include "Output.h"
#include "Classic.h"
#include "Doughnut.h"
#include "Cell.h"
#include "Mirror.h"
#include "Grid.h"
#include <fstream>
#include <iostream>

using namespace std;

/*
  Output()
  the Output() function is the constructor that sets fileType, modeType,
  fileName, and pauseRequest to "", num to 2, and gen to 1
  @param N/A
  @return N/A
*/
Output::Output() {
 fileType = "";
 modeType = "";
 fileName = "";
 pauseRequest = "";
 Xcounter;
 num = 2;
 gen = 1;
 same;
}

/*
  ~Output()
  the ~Output() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
Output::~Output() {
  string s = "deleted";
}

/*
  userInput()
  the userInput() function prompts the user for whether they want a random grid
  config or a map grid config, which mode they want, and if they want to pause
  between generations or not
  @param N/A
  @return N/A
*/
void Output::userInput() {
  cout << "Would you like the map file or a random file? Please type in map or random: " << endl;
  cin >> fileType;
  if (fileType == "map") {
    cout << "Enter the input file name (with .txt extension): " << endl;
    cin >> fileName;
    cout << "Which mode would you like to run the simulation in? Please type in classic, doughnut, or mirror: " << endl;
    cin >> modeType;
    cout << "Would you like to pause between the generations, yes or no?" << endl;
    cin >> pauseRequest;

    if (pauseRequest == "yes") {
      Grid gr;
      gr.createMapGrid(fileName);
      cout << "Gen 0" << endl;
      gr.printGrid();
      cout << endl;
      if (modeType == "classic") {
        classicOutput(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "doughnut") {
        doughnutOutput(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "mirror") {
        mirrorOutput(gr.grid, gr.rows, gr.cols);
      }
    }

    else if (pauseRequest == "no") {
      ofstream out_file;

      cout << "Enter the output file name (with .txt extension): " << endl;
      cin >> outputFile;

      out_file.open(outputFile);
      Grid gr;
      gr.createMapGrid(fileName);

      out_file << "Gen 0" << endl;
      gr.outputGrid(outputFile);

      if (modeType == "classic") {
        classicOutputFile(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "doughnut") {
        doughnutOutputFile(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "mirror") {
        mirrorOutputFile(gr.grid, gr.rows, gr.cols);
      }

      out_file.close();
    }
  }

  else if (fileType == "random") {
    Grid gr;
    gr.createRandGrid();

    cout << "Which mode would you like to run the simulation in? Please type in classic, doughnut, or mirror: " << endl;
    cin >> modeType;
    cout << "Would you like to pause between the generations, yes or no?" << endl;
    cin >> pauseRequest;

    if (pauseRequest == "yes") {
      cout << "Gen 0" << endl;
      gr.printGrid();
      cout << endl;

      if (modeType == "classic") {
        classicOutput(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "doughnut") {
        doughnutOutput(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "mirror") {
        mirrorOutput(gr.grid, gr.rows, gr.cols);
      }
    }

    else if (pauseRequest == "no") {
      ofstream out_file;

      cout << "Enter the output file name (with .txt extension): " << endl;
      cin >> outputFile;

      out_file.open(outputFile);
      out_file << "Gen 0" << endl;
      gr.outputGrid(outputFile);

      if (modeType == "classic") {
        classicOutputFile(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "doughnut") {
        doughnutOutputFile(gr.grid, gr.rows, gr.cols);
      }

      else if (modeType == "mirror") {
        mirrorOutputFile(gr.grid, gr.rows, gr.cols);
      }

      out_file.close();
    }
  }
}

/*
  classicOutput()
  the classicOutput() function takes in a grid, rows, and cols and uses a while
  loop to execute the generations in classic mode and pausing between them
  before ending in an infinite loop, in stabilized bacteria, or an empty grid
  @param char** g, int rows, int cols; prints to the screen
  @return N/A
*/
void Output::classicOutput(char **g, int rows, int cols) {
  Classic c;

  cout << "Press enter to get each generation simulation: " << endl;

  while (cin.get()) {
    same = 0;
    Xcounter = 0;

    if (gen == 1) {
      if (cin.get()) {
        cout << "Gen 1" << endl;
        c.classicMode(g, rows, cols);
        c.printGrid(g, rows, cols);
      }

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (c.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (g[i][j] == c.newGrid[i][j]) {
            same++;
          }
        }
      }

      if (Xcounter == 0) {
        cout << "There is no bacteria in the simulation. Please press enter to exit.";
        if (cin.get()) {
          break;
        }
      }

      else if (same == rows * cols) {
        cout << "Bacteria is stabilized. Please press enter to exit.";  //TEST OUT!!!!
        if (cin.get()) {
          break;
        }
      }
    }

    gen++;
    if (gen > 2) {
      Classic classicGrid;
      cout << "Gen " << num << endl;
      num++;
      classicGrid.newGrid = c.newGrid;
      c.classicMode(c.newGrid,rows,cols);
      c.printGrid(c.newGrid, rows, cols);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (c.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (classicGrid.newGrid[i][j] == c.newGrid[i][j]) {
            same++;
          }
        }
      }
    }

    if (Xcounter == 0) {
      cout << "There is no bacteria in the simulation. Please press enter to exit." << endl;
      if (cin.get()) {
        break;
      }
    }

    else if (same == rows * cols) {
      cout << "Bacteria is stabilized. Please press enter to exit." << endl;  //TEST OUT!!!!
      if (cin.get()) {
        break;
      }
    }
  }
}

/*
  doughnutOutput()
  the doughnutOutput() function takes in a grid, rows, and cols and uses a while
  loop to execute the generations in doughnut mode and pausing between them
  before ending in an infinite loop, in stabilized bacteria, or an empty grid
  @param char** g, int rows, int cols; prints to the screen
  @return N/A
*/
void Output::doughnutOutput(char **g, int rows, int cols) {
  Doughnut d;

  cout << "Press enter to get each generation simulation: " << endl;

  while (cin.get()) {
    same = 0;
    Xcounter = 0;

    if (gen == 1) {
      if (cin.get()) {
        cout<<"Gen 1"<<endl;
        d.doughnutMode(g, rows, cols);
        d.printGrid(g, rows, cols);
      }

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (d.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (g[i][j] == d.newGrid[i][j]) {
           same++;
          }
        }
      }
      //cout<<"Same: "<<same<<endl;

      if (Xcounter == 0) {
        cout << "There is no bacteria in the simulation. Please press enter to exit.";
        if (cin.get()) {
          break;
        }
      }

      else if (same == rows * cols) {
        cout << "Bacteria is stabilized. Please press enter to exit.";  //TEST OUT!!!!
        if (cin.get())  {
          break;
        }
      }
    }

    gen++;
    if (gen > 2) {
      Doughnut doughnutGrid;
      cout << "Gen " << num << endl;
      num++;
      doughnutGrid.newGrid = d.newGrid;    //grid before update
      d.doughnutMode(d.newGrid, rows, cols);
      d.printGrid(d.newGrid, rows, cols);

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (d.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (doughnutGrid.newGrid[i][j] == d.newGrid[i][j]) {
            same++;
          }
        }
      }
    }

    if (Xcounter == 0){
      cout << "There is no bacteria in the simulation. Please press enter to exit." << endl;
      if (cin.get()) {
        break;
      }
    }

    else if (same == rows * cols) {
      cout << "Bacteria is stabilized. Please press enter to exit." << endl;  //TEST OUT!!!!
      if (cin.get()) {
        break;
      }
    }
  }
}

/*
  mirrorOutput()
  the mirrorOutput() function takes in a grid, rows, and cols and uses a while
  loop to execute the generations in mirror mode and pausing between them
  before ending in an infinite loop, in stabilized bacteria, or an empty grid
  @param char** g, int rows, int cols; prints to the screen
  @return N/A
*/
void Output::mirrorOutput(char **g, int rows, int cols) {
  Mirror m;
  cout << "Press enter to get each generation simulation: " << endl;

  while (cin.get()) {
    same = 0;
    Xcounter = 0;

    if (gen == 1) {
      if (cin.get()) {
        cout<<"Gen 1"<<endl;
        m.mirrorMode(g, rows, cols);
        m.printGrid(g, rows, cols);
      }

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (m.newGrid[i][j] == 'X') {
            Xcounter++;
          }
          if (g[i][j] == m.newGrid[i][j]) {
            same++;
          }
        }
      }

      if (Xcounter == 0) {
        cout << "There is no bacteria in the simulation. Please press enter to exit.";
        if (cin.get()) {
          break;
        }
      }

      else if (same == rows * cols) {
        cout << "Bacteria is stabilized. Please press enter to exit.";  //TEST OUT!!!!
        if (cin.get()) {
          break;
        }
      }
    }

    gen++;
    if(gen>2) {
      Mirror mirrorGrid;
      cout << "Gen " << num << endl;
      num++;
      mirrorGrid.newGrid = m.newGrid;
      m.mirrorMode(m.newGrid,rows,cols);
      m.printGrid(m.newGrid, rows, cols);

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (m.newGrid[i][j] == 'X') {
            Xcounter++;
          }
          if (mirrorGrid.newGrid[i][j] == m.newGrid[i][j]) {
            same++;
          }
        }
      }
    }

    if (Xcounter == 0) {
      cout << "There is no bacteria in the simulation. Please press enter to exit." << endl;
      if (cin.get()) {
        break;
      }
    }

    else if (same == rows * cols) {
      cout << "Bacteria is stabilized. Please press enter to exit.";  //TEST OUT!!!!
      if (cin.get()) {
        break;
      }
    }
  }
}

/*
  classicOutputFile()
  the classicOutputFile() function takes in a grid, rows, and cols and uses a
  while loop to execute the generations in classic mode and pausing between them
  before ending in an infinite loop, in stabilized bacteria, or an empty grid
  @param char** g, int rows, int cols; prints to the text file given by the user
  @return N/A
*/
void Output::classicOutputFile(char **g, int rows, int cols){
  Classic c;
  ofstream out_file;
  out_file.open(outputFile, ios::app);

  while (Xcounter != 0 || same != rows * cols) {
    same = 0;
    Xcounter = 0;

    if (gen == 1) {
      out_file << endl;
      out_file << "Gen 1" << endl;
      c.classicMode(g, rows, cols);
      c.outputGrid(g, rows, cols, outputFile);
      out_file << endl;

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (c.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (g[i][j] == c.newGrid[i][j]) {
            same++;
          }
        }
      }

      if (Xcounter == 0) {
        out_file << "There is no bacteria in the simulation.";
        return;
      }

      else if (same == rows * cols) {
        out_file << "Bacteria is stabilized.";  //TEST OUT!!!!
        return;
      }
    }

    gen++;
    if (gen > 2) {
      Classic classicGrid;
      out_file << "Gen " << num << endl;
      num++;
      classicGrid.newGrid = c.newGrid;
      c.classicMode(c.newGrid, rows, cols);
      c.outputGrid(c.newGrid, rows, cols, outputFile);
      out_file << endl;
      for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
          if (c.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (classicGrid.newGrid[i][j] == c.newGrid[i][j]) {
            same++;
          }
        }
      }
    }

    if (Xcounter == 0) {
      out_file << "There is no bacteria in the simulation.";
      return;
    }

    else if (same == rows * cols) {
      out_file << "Bacteria is stabilized.";
      return;
    }
  }
  out_file.close();
}

/*
  doughnutOutputFile()
  the doughnutOutputFile() function takes in a grid, rows, and cols and uses a
  while loop to execute the generations in doughnut mode and pausing between them
  before ending in an infinite loop, in stabilized bacteria, or an empty grid
  @param char** g, int rows, int cols; prints to the text file given by the user
  @return N/A
*/
void Output::doughnutOutputFile(char **g, int rows, int cols){
  Doughnut d;
  ofstream out_file;
  out_file.open(outputFile, ios::app);

  while (Xcounter != 0 || same != rows * cols) {
    same = 0;
    Xcounter = 0;

    if (gen == 1) {
      out_file << endl;
      out_file << "Gen 1" << endl;
      d.doughnutMode(g, rows, cols);
      d.outputGrid(g, rows, cols, outputFile);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (d.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (g[i][j] == d.newGrid[i][j]) {
            same++;
          }
        }
      }

      if (Xcounter == 0) {
        out_file << "There is no bacteria in the simulation.";
        return;
      }
      else if (same == rows * cols) {
        out_file << "Bacteria is stabilized.";
        return;
      }
    }

    gen++;
    if (gen > 2) {
      Doughnut doughnutGrid;
      out_file << "Gen " << num << endl;
      num++;
      doughnutGrid.newGrid = d.newGrid;
      d.doughnutMode(d.newGrid,rows,cols);
      d.outputGrid(d.newGrid, rows, cols, outputFile);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (d.newGrid[i][j] == 'X') {
            Xcounter++;
          }
          if (doughnutGrid.newGrid[i][j] == d.newGrid[i][j]) {
            same++;
          }
        }
      }
    }

    if (Xcounter == 0) {
      out_file << "There is no bacteria in the simulation.";
      return;
    }
    else if (same == rows * cols) {
      out_file << "Bacteria is stabilized.";
      return;
    }
  }
  out_file.close();
}

/*
  mirrorOutputFile()
  the mirrorOutputFile() function takes in a grid, rows, and cols and uses a
  while loop to execute the generations in mirror mode and pausing between them
  before ending in an infinite loop, in stabilized bacteria, or an empty grid
  @param char** g, int rows, int cols; prints to the text file given by the user
  @return N/A
*/
void Output::mirrorOutputFile(char **g, int rows, int cols){
  Mirror m;
  ofstream out_file;
  out_file.open(outputFile, ios::app);

  while (Xcounter != 0 || same != rows * cols) {
    same = 0;
    Xcounter = 0;

    if (gen == 1) {
      out_file << endl;
      out_file << "Gen 1" << endl;
      m.mirrorMode(g, rows, cols);
      m.outputGrid(g, rows, cols, outputFile);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (m.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (g[i][j] == m.newGrid[i][j]) {
            same++;
          }
        }
      }

      if (Xcounter == 0) {
        out_file << "There is no bacteria in the simulation.";
        return;
      }

      else if (same == rows * cols) {
        out_file << "Bacteria is stabilized.";
        return;
      }
    }

    gen++;
    if (gen > 2) {
      Mirror mirrorGrid;
      out_file << "Gen " << num << endl;
      num++;
      mirrorGrid.newGrid = m.newGrid;
      m.mirrorMode(m.newGrid,rows,cols);
      m.outputGrid(m.newGrid, rows, cols, outputFile);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (m.newGrid[i][j] == 'X') {
            Xcounter++;
          }

          if (mirrorGrid.newGrid[i][j] == m.newGrid[i][j]) {
            same++;
          }
        }
      }
    }

    if (Xcounter == 0) {
      out_file << "There is no bacteria in the simulation.";
      return;
    }
    else if (same == rows * cols) {
      out_file << "Bacteria is stabilized.";
      return;
    }
  }
  out_file.close();
}
