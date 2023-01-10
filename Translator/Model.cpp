/*
  Model.cpp is the class file for Model which declares the variables and
  functions mentioned in the header file
*/
#include "Model.h"
#include <iostream>
#include <string>

using namespace std;

/*
  Model()
  the Model() function is the constructor that sets the tutword variable to ""
  @param N/A
  @return N/A
*/
Model::Model(){
  tutword = "";
}

/*
  ~Model()
  the ~Model() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
Model::~Model(){
  cout << "deleted" << endl;
}

/*
  translateSingleCharacter()
  the translateSingleCharacter() function converts a given character to its
  corresponding tutnese word
  @param char c
  @return string tutword
*/
string Model::translateSingleCharacter(char c) {
  if (c == 'A') {tutword = "A";}
  else if (c == 'B') {tutword = "Bub";}
  else if (c == 'C') {tutword = "Cash";}
  else if (c == 'D') {tutword = "Dud";}
  else if (c == 'E') {tutword = "E";}
  else if (c == 'F') {tutword = "Fuf";}
  else if (c == 'G') {tutword = "Gug";}
  else if (c == 'H') {tutword = "Hash";}
  else if (c == 'I') {tutword = "I";}
  else if (c == 'J') {tutword = "Jay";}
  else if (c == 'K') {tutword = "Kuck";}
  else if (c == 'L') {tutword = "Lul";}
  else if (c == 'M') {tutword = "Mum";}
  else if (c == 'N') {tutword = "Nun";}
  else if (c == 'O') {tutword = "O";}
  else if (c == 'P') {tutword = "Pub";}
  else if (c == 'Q') {tutword = "Quack";}
  else if (c == 'R') {tutword = "Rug";}
  else if (c == 'S') {tutword = "Sus";}
  else if (c == 'T') {tutword = "Tut";}
  else if (c == 'U') {tutword = "U";}
  else if (c == 'V') {tutword = "Vuv";}
  else if (c == 'W') {tutword = "Wack";}
  else if (c == 'X') {tutword = "Ex";}
  else if (c == 'Y') {tutword = "Yub";}
  else if (c == 'Z') {tutword = "Zub";}
  else if (c == 'a') {tutword = "a";}
  else if (c == 'b') {tutword = "bub";}
  else if (c == 'c') {tutword = "cash";}
  else if (c == 'd') {tutword = "dud";}
  else if (c == 'e') {tutword = "e";}
  else if (c == 'f') {tutword = "fuf";}
  else if (c == 'g') {tutword = "gug";}
  else if (c == 'h') {tutword = "hash";}
  else if (c == 'i') {tutword = "i";}
  else if (c == 'j') {tutword = "jay";}
  else if (c == 'k') {tutword = "kuck";}
  else if (c == 'l') {tutword = "lul";}
  else if (c == 'm') {tutword = "mum";}
  else if (c == 'n') {tutword = "nun";}
  else if (c == 'o') {tutword = "o";}
  else if (c == 'p') {tutword = "pub";}
  else if (c == 'q') {tutword = "quack";}
  else if (c == 'r') {tutword = "rug";}
  else if (c == 's') {tutword = "sus";}
  else if (c == 't') {tutword = "tut";}
  else if (c == 'u') {tutword = "u";}
  else if (c == 'v') {tutword = "vuv";}
  else if (c == 'w') {tutword = "wack";}
  else if (c == 'x') {tutword = "ex";}
  else if (c == 'y') {tutword = "yub";}
  else if (c == 'z') {tutword = "zub";}
  return tutword;
}

/*
  translateDoubleCharacter()
  the translateDoubleCharacter() function converts a given character to its
  corresponding double-lettered tutnese word
  @param char c
  @return string tutword
*/
string Model::translateDoubleCharacter(char c){
  if (c == 'A') {tutword = "SquatA";}
  else if (c == 'B') {tutword = "SquaBub";}
  else if (c == 'C') {tutword = "SquaCash";}
  else if (c == 'D') {tutword = "SquaDud";}
  else if (c == 'E') {tutword = "SquatE";}
  else if (c == 'F') {tutword = "SquaFuf";}
  else if (c == 'G') {tutword = "SquaGug";}
  else if (c == 'H') {tutword = "SquaHash";}
  else if (c == 'I') {tutword = "SquatI";}
  else if (c == 'J') {tutword = "SquaJay";}
  else if (c == 'K') {tutword = "SquaKuck";}
  else if (c == 'L') {tutword = "SquaLul";}
  else if (c == 'M') {tutword = "SquaMum";}
  else if (c == 'N') {tutword = "SquaNun";}
  else if (c == 'O') {tutword = "SquatO";}
  else if (c == 'P') {tutword = "SquaPub";}
  else if (c == 'Q') {tutword = "SquaQuack";}
  else if (c == 'R') {tutword = "SquaRug";}
  else if (c == 'S') {tutword = "SquaSus";}
  else if (c == 'T') {tutword = "SquaTut";}
  else if (c == 'U') {tutword = "SquatU";}
  else if (c == 'V') {tutword = "SquaVuv";}
  else if (c == 'W') {tutword = "SquaWack";}
  else if (c == 'X') {tutword = "SquaEx";}
  else if (c == 'Y') {tutword = "SquaYub";}
  else if (c == 'Z') {tutword = "SquaZub";}
  else if (c == 'a') {tutword = "squata";}
  else if (c == 'b') {tutword = "squabub";}
  else if (c == 'c') {tutword = "squacash";}
  else if (c == 'd') {tutword = "squadud";}
  else if (c == 'e') {tutword = "squate";}
  else if (c == 'f') {tutword = "squafuf";}
  else if (c == 'g') {tutword = "squagug";}
  else if (c == 'h') {tutword = "squahash";}
  else if (c == 'i') {tutword = "squati";}
  else if (c == 'j') {tutword = "squajay";}
  else if (c == 'k') {tutword = "squakuck";}
  else if (c == 'l') {tutword = "squalul";}
  else if (c == 'm') {tutword = "squamum";}
  else if (c == 'n') {tutword = "squanun";}
  else if (c == 'o') {tutword = "squato";}
  else if (c == 'p') {tutword = "squapub";}
  else if (c == 'q') {tutword = "squaquack";}
  else if (c == 'r') {tutword = "squarug";}
  else if (c == 's') {tutword = "squasus";}
  else if (c == 't') {tutword = "squatut";}
  else if (c == 'u') {tutword = "squatu";}
  else if (c == 'v') {tutword = "squavuv";}
  else if (c == 'w') {tutword = "squawack";}
  else if (c == 'x') {tutword = "squaex";}
  else if (c == 'y') {tutword = "squayub";}
  else if (c == 'z') {tutword = "squazub";}
  return tutword;
}
