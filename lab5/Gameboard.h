#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Gameboard {
private:
	int m_guessesLeft;
	int m_i;
	bool m_hasWon;
	bool m_hasLost;
	unordered_set<string> m_guesses[26];
	string m_progress;
	string m_word;
	bool hasGuessed(string guess);
public:
	Gameboard(string word);
	bool guess(string guess);
	int getGuessesLeft() { return m_guessesLeft; }
	bool getHasWon() { return m_hasWon; }
	bool getHasLost() { return m_hasLost; }
	string getProgress() { return m_progress; }
	string getWord() { return m_word; }
};

#endif