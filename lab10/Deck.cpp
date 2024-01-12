#include "Deck.h"

Deck::Deck() : topCard(0)
{
	for (int i = 0; i < 52; i++)
	{
		string name = to_string((i % 13) + 1);
		int value = (i % 13) + 1;
		int temp = i % 13;
		if (temp == 0) {
			name = "Ace";
			value = 11;
		}
		else if (temp == 12) {
			name = "King";
			value = 10;
		}
		else if (temp == 11) {
			name = "Queen";
			value = 10;
		}
		else if (temp == 10) {
			name = "Jack";
			value = 10;
		}
		Card card(name, cardSuits.at(i / 13), value);
		cards.push_back(card);
	}
}

void Deck::shuffle()
{
	srand(time(0));

	for (int i = cards.size() - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}

Card Deck::draw()
{
	Card c = cards.at(topCard);
	topCard++;
	return c;
}
