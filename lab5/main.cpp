#include "Dictionary.h"
#include "Gameboard.h"

int main() {
	string input = "-1";
	string filename;
	int wins = 0;
	int losses = 0;
	bool isFirstLoop = true;

	cout << "Welcome to hangman!" << endl;
	cout << "Enter difficulty level (1-3): ";
	cin >> input;
	while (stoi(input) > 3 || stoi(input) < 1) {
		cout << "Invalid input!" << endl;
		cout << "Enter difficulty level (1-3): ";
		cin >> input;
	}

	Dictionary* dict = new Dictionary("dict_lvl" + input + ".txt");
	Gameboard* gb = new Gameboard(dict->getWord());

	while (input.compare("-1")) {
		if (isFirstLoop) {
			cout << "Guess the word!" << endl;
			cout << gb->getProgress() << endl;
			cout << "Enter your guess (One letter): ";
			cin >> input;
			cout << endl;
			isFirstLoop = false;
		}
		if (input.length() != 1) {
			cout << "Invalid input!";
			cout << "What is your guess? (One letter): ";
			cin >> input;
			continue;
		}

		gb->guess(input);

		if (gb->getHasWon()) {
			cout << "You won! The word was " + gb->getWord() << endl;
			wins++;
		}
		else if (gb->getHasLost()) {
			cout << "You lost! The word was " + gb->getWord() << endl;
			losses++;
		}
		else {
			cout << gb->getProgress() << endl;
			cout << "What is your guess? (One letter): ";
			cin >> input;
		}

		if (gb->getHasLost() || gb->getHasWon()) {
			cout << "Wins: " + to_string(wins) << endl;
			cout << "Losses: " + to_string(losses) << endl;
			cout << "Play again? [y]es or [n]o: ";
			cin >> input;
			if (!input.compare("n")) {
				cout << "Goodbye!";
				break;
			}
			else {
				gb = new Gameboard(dict->getWord());
				isFirstLoop = true;
			}
		}
	}


	return 0;
}