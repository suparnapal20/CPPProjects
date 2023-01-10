/*
  Translator.cpp is the class file for Translator which declares the variables
  and functions mentioned in the header file
*/
#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <string>

using namespace std;

/*
  Translator()
  the Translator() function is the constructor that sets the i variable to 0
  and the string variables to "" (empty string)
  @param N/A
  @return N/A
*/
Translator::Translator(){
  i = 0;
  translatedWord = "";
  translatedSent = "";
  w = "";
}

/*
  ~Translator()
  the ~Translator() function is the destructor that destroys the class
  @param N/A
  @return N/A
*/
Translator::~Translator(){
  cout << "deleted" << endl;
}

/*
  translateEnglishWord()
  the translateEnglishWord() function translates a given word to tutnese
  @param string word
  @return string translation
*/
string Translator::translateEnglishWord(string word) {
  Model model;
  string translation = "";

  for (int j = 0; j < word.length(); j++) {
    if (word[j] == word[j + 1]) {
      translation += model.translateDoubleCharacter(word[j]);
      j += 1;
    }
    else {
      translation += model.translateSingleCharacter(word[j]);
    }
  }
  return translation;
}

/*
  translateEnglishSentence()
  the translateEnglishSentence() function translates a given sentence to tutnese
  @param string sent
  @return string translatedSent
*/
string Translator::translateEnglishSentence(string sent) {
  for (char c : sent) {
    if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?') {
      translatedSent += translateEnglishWord(w);
      translatedSent += c;
      w = "";
    }
    else {
      w += c;
    }
  }
  return translatedSent;
}
