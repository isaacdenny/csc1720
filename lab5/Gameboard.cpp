#include "Gameboard.h"

Gameboard::Gameboard(string word) : m_guessesLeft(6), m_word(word), m_i(0), m_hasWon(false), m_hasLost(false)
{
	m_progress = "-";
	for (size_t i = 0; i < word.length() - 1; i++)
	{
		m_progress += "-";
	}
}

bool Gameboard::guess(string guess) 
{
	for (auto& x : guess) {
		x = tolower(x);
	}

	if (hasGuessed(guess)) {
		cout << "You already guessed " + guess << endl;
		return false;
	}
	m_guesses->insert(guess);
	m_i++;

	size_t pos = 0;
	pos = m_word.find_first_of(guess);
	if (pos == string::npos) {
		cout << "There is no " + guess << endl;
		m_guessesLeft--;
		if (m_progress.find("-") == string::npos) {
			m_hasWon = true;
		}
		else if (m_guessesLeft <= 0) {
			m_hasLost = true;
		}
		return false;
	}

	while ((pos = m_word.find(guess, pos)) != string::npos) {
		m_progress.replace(pos, guess.length(), guess);
		pos += guess.length();
	}

	if (m_progress.find("-") == string::npos) {
		m_hasWon = true;
	}
	else if (m_guessesLeft <= 0) {
		m_hasLost = true;
	}

	cout << "Your guess was correct!";
	cout << endl;
	return true;
}

bool Gameboard::hasGuessed(string guess) {
	if (m_guesses->count(guess) > 0) {
		return true;
	}
	return false;
}