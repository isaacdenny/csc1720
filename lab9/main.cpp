#include<iostream>
#include<cstdlib>
#include<vector>
#include"Deck.h"

using namespace std;

int main() {
	Deck deck;
	deck.shuffle();
	int money = 100;

	while (true) {
		string input = "";
		int bet = 0;
		cout << "\nWelcome to SummerCards!" << endl;
		cout << "You have $" << money << endl;
		cout << "Would you like to play? (y/n): ";
		cin >> input;
		if (input != "y") {
			cout << "Goodbye!";
			break;
		}

		cout << "What is your bet? ";
		cin >> bet;
		while (bet <= 0 || bet > money) {
			cout << "Bet invalid!" << endl;
			cout << "What is your bet? ";
			cin >> bet;
		}
		money -= bet;
		int compBet = rand() % 50 + 1;
		cout << "The Computer bet " << compBet << endl;
		int pot = bet + compBet;
		
		vector<Card> drawnCards;
		int playerVal = 0;
		int compVal = 0;
		for (int i = 0; i < 6; i++)
		{
			drawnCards.push_back(deck.draw());
		}
		for (int i = 0; i < drawnCards.size(); i++)
		{
			if (i % 2 == 0) {
				cout << "\nYou drew a " + drawnCards.at(i).getFullName() << endl;
				playerVal += drawnCards.at(i).getValue();
			}
			else {
				cout << "\nThe Computer drew a " + drawnCards.at(i).getFullName() << endl;
				compVal += drawnCards.at(i).getValue();
			}
		}

		if (playerVal == compVal) {
			cout << "\nIt's a tie!" << endl;
			money += bet;
			pot = 0;
		}
		else if (playerVal < compVal) {
			cout << "\nThe Computer wins!" << endl;
			pot = 0;
		}
		else {
			cout << "\nYou win!" << endl;
			money += pot;
		}
	}
	return 0;
}