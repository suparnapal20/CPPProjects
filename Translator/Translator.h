/*
  Translator.h is the header file that declares the names and types of the i,
  translated word, translated sentence, and w variables and the function names
*/
#include <iostream>

using namespace std;

class Translator {
  private:
    int i;
    string translatedWord;
    string translatedSent;
    string w;
  public:
    Translator();
    ~Translator();
    string translateEnglishWord(string word);
    string translateEnglishSentence(string sent);
};
