#ifndef DECK_H
#define DECK_H

#include<string>
#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Card.h"
using namespace std;

static vector<string> cardSuits = { "Clubs", "Diamonds", "Hearts", "Spades" };

class Deck {
private:
	vector<Card> cards;
	int topCard;
public:
	Deck();
	void shuffle();
	Card draw();
};

#endif