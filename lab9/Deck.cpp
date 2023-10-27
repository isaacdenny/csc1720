#include "Deck.h"

Deck::Deck() : topCard(0)
{
	for (int i = 0; i < 52; i++)
	{
		string name = to_string((i % 13) + 1);
		int temp = i % 13;
		if (temp == 0) {
			name = "Ace";
		}
		else if (temp == 12) {
			name = "King";
		}
		else if (temp == 11) {
			name = "Queen";
		}
		else if (temp == 10) {
			name = "Jack";
		}
		Card card(name, cardSuits.at(i / 13), (i % 13) + 1);
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
