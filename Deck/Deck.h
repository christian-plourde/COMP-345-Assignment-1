#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
	private:
		Card theDeck[64];

	public:
		Deck();
		void Print();
		void Shuffle();
		void EmptyDeck();
		Card DealACard():
};
#endif