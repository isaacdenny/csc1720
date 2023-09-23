#include "Dictionary.h"

Dictionary::Dictionary(string fn) : m_fileName(fn)
{
	ifstream in;
	in.open(m_fileName);
	string line;
	int i = 0;
	while (getline(in, line)) {
		for (auto& x : line) {
			x = tolower(x);
		}
		m_words[i] = line;
		i++;
	}
}

string Dictionary::getWord()
{
	srand(time(NULL));
	int i = rand() % 100;
	return m_words[i];
}
