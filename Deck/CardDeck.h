#ifndef CARDDECK_H
#define CARDDECK_H

#include "Card.h"
#include "../Graph/SinglyLinkedList.h"

class CardDeck
{
	private:
		Card specialCards[2];
		Card cardDeck[64];
		SinglyLinkedList<Card> cardDeckList;
		SinglyLinkedList<Card> discardedCards;
		int currentCard;

	public:
		CardDeck();
		~CardDeck();

		SinglyLinkedList<Card>* getDeck();
		SinglyLinkedList<Card>* getDiscardedDeck();

		void Print(SinglyLinkedList<Card>*);
		void Shuffle();
		bool isEmptyDeck();
		bool isEmptyDiscardedDeck();
		Card SelectACard(SinglyLinkedList<Card>);
		void discardCard(Card, SinglyLinkedList<Card>);
};
#endif