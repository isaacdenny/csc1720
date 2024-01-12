#include<iostream>
#include<random>
#include"Deck.h"
#include"Hand.h"

using namespace std;

void showMenu();

void initGame(Deck& d, Hand& ph, Hand& dh);

bool dealerHits(Hand& h);

int endGame(int pv, int dv, int bet, bool dbust);

void getBet(int& bet, int& money);

int main() {
	cout << "\nWelcome to Blackjack!" << endl;
	int money = 100;
	while (true) {
		string input = "";
		Hand phand;
		Hand dhand;
		Deck deck;

		cout << "You have $" << money << endl;
		cout << "Would you like to play? (y/n): ";
		cin >> input;
		if (input != "y") {
			cout << "Goodbye!";
			break;
		}

		initGame(deck, phand, dhand);

		int bet = 0;
		bool pstands = false;
		bool shouldDraw = false;

		char menuInput = 'm';
		getBet(bet, money);
		Card c = deck.draw();
		while (menuInput != 'q') {
			if (shouldDraw) {
				c = deck.draw();
				shouldDraw = false;
			}

			if (!pstands) {
				switch (menuInput) {
				case 'm':
					showMenu();
					break;
				case 'h':
					if (phand.addCard(c)) {
						cout << "You drew a " << c.getFullName() << endl;
						shouldDraw = true;
					}
					else {
						cout << "You have already hit 5 times!" << endl;
					}
					break;
				case 's':
					cout << "You chose to stand" << endl;
					pstands = true;
					continue;
					break;
				default:
					menuInput = 'm';
					break;
				}

				if (phand.getHandValue() > 21) {
					cout << "You went over 21!" << endl;
					cout << "\nyOu lOSe\n" << endl;
					break;
				}

				cout << "\nDealer hand:\n\n";
				dhand.printHand(false);

				cout << "\nYour hand:\n\n";
				phand.printHand(true);
				cout << "Hand total: " << phand.getHandValue() << endl;

				cout << "\nWhat will you do? ";
				cin >> menuInput;
			}
			else {
				if (dealerHits(dhand)) {
					cout << "\nDealer hand:\n\n";
					dhand.printHand(true);
					cout << "The Dealer Hits!" << endl;
					dhand.addCard(c);
					cout << "The Dealer drew a " << c.getFullName() << endl;
					if (dhand.getHandValue() > 21) {
						cout << "The Dealer went over 21!" << endl;
						cout << "\nYou Win!\n" << endl;
						money += endGame(phand.getHandValue(), dhand.getHandValue(), bet, true);
						break;
					}
					shouldDraw = true;
				}
				else {
					cout << "\nDealer hand:\n\n";
					dhand.printHand(true);
					cout << "The Dealer Stands!" << endl;
					if (pstands) {
						money += endGame(phand.getHandValue(), dhand.getHandValue(), bet, false);
						break;
					}
				}
			}
		}
	}
	return 0;
}

void getBet(int& bet, int& money)
{
	cout << "What is your bet? ";
	cin >> bet;
	while (bet <= 0 || bet > money) {
		cout << "Bet invalid!" << endl;
		cout << "What is your bet? ";
		cin >> bet;
		cout << endl;
	}
	money -= bet;
}

bool dealerHits(Hand& h)
{
	if (h.getHandValue() > 16) {
		return false;
	}
	else {
		return true;
	}
}

int endGame(int pv, int dv, int bet, bool dbust)
{
	if (dbust) {
		return bet;
	}

	int x = 0;
	if (pv > dv) {
		cout << "YOU WIN!" << endl;
		x = bet * 2;
	}
	else if (pv == dv) {
		cout << "It's a push... you get your bet back!" << endl;
		x = bet;
	}
	else {
		cout << "DEALER WINS!" << endl;
		cout << "yOu LoSE" << endl;
	}

	cout << "Your hand value: " << pv << endl;
	cout << "Dealer hand value: " << dv << endl;
	return x;
}

void initGame(Deck& d, Hand& ph, Hand& dh)
{
	d.shuffle();
	ph.addCard(d.draw());
	dh.addCard(d.draw());
	ph.addCard(d.draw());
	dh.addCard(d.draw());
}

void showMenu() {
	cout << endl;
	cout << "[H]it" << endl;
	cout << "[S]tand" << endl;
	cout << "[Q]uit" << endl;
}