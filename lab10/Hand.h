#ifndef HAND_H
#define HAND_H

#include<vector>
#include<iostream>
#include"Card.h"

using namespace std;

class Hand {
private:
	vector<Card> cards;
public:
	bool addCard(Card c);
	int getHandValue();
	void printHand(bool showAll); // why
	void clearHand();
};

#endif
