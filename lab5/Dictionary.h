#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

using namespace std;

class Dictionary {
private:
	string m_fileName;
	string m_words[100];
public:
	Dictionary(string fn);
	string getWord();
};

#endif