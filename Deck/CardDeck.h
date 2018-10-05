#ifndef CARDDECK_H
#define CARDDECK_H

#include "Card.h"
#include<stack>

class CardDeck
{
	private: 
		Card cardDeck[62];     // + 2 for special cards
		int currentCard;
		stack<Card> discardedCards;

	public:
		CardDeck();
		~CardDeck();

		void Print();
		void Shuffle();
		bool isEmptyDeck();
		bool isEmptyDiscardedDeck();
		Card SelectACardFromDeck();
		Card SelectACardFromDiscardedDeck();
		void discardCard(Card);
};
#endif