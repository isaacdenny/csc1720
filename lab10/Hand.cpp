#include "Hand.h"

bool Hand::addCard(Card c)
{
	if (cards.size() >= 5)
		return false;
	cards.push_back(c);
	return true;
}

int Hand::getHandValue()
{
	int sum = 0;
	for (int i = 0; i < cards.size(); i++)
	{
		sum += cards[i].getValue();
	}
	return sum;
}

void Hand::printHand(bool showAll)
{
	cout << endl;
	for (int i = 0; i < cards.size(); i++)
	{
		if (!showAll && i == 0) {
			cout << "HIDDEN" << endl;
		}
		else {
			cout << cards[i].getFullName() << endl;
		}
	}
	cout << endl;
}

void Hand::clearHand()
{
	cards.clear();
}
