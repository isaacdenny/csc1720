#ifndef CARD_H
#define CARD_H

#include<vector>
#include<string>
using namespace std;

class Card {
private:
	string name;
	string suit;
	int value;
public:
	Card(string n, string s, int v);
	string getFullName() { return name + " of " + suit; }
	string getSuit() { return suit; }
	string getName() { return name; }
	int getValue() { return value; }
};

#endif