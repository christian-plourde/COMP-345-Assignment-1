#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "Card.h"
#include "CardDeck.h"
using namespace std;

int stringToInt(string);
HowTo stringToHowTo(string);


CardDeck::CardDeck() {
	string fname = "cards.csv";
	string n, c, h, e;
	ifstream file(fname);
	int count = 0;
	if (file) {
		while (getline(file, n, ',')) {
			cardDeck[count].setName(n);
			getline(file, c, ',');
			cardDeck[count].setCost(stringToInt(c));
			getline(file, h, ',');
			cardDeck[count].setHowTo(stringToHowTo(h));
			getline(file, e);
			cardDeck[count].setEffect(e);
			count++;
		}
		file.close();
	}
	else
		cout << "ERROR: FAILURE TO OPEN FILE";
}

#include<sstream>
int stringToInt(string n) {
	stringstream num(n);
	int x;
	num >> x;
	return x;
}

HowTo stringToHowTo(string h) {
	int x = stringToInt(h);
	switch (x) {
		case 0: return Empty; break;
		case 1: return Goal; break;
		case 2: return Keep; break;
		case 3: return Discard;
	}
}

CardDeck::~CardDeck() {
	//delete[] cardDeck;
}

void CardDeck::Print() {
	for (Card c : cardDeck)
		c.Print();
}

void CardDeck::Shuffle() {
	srand(time(0));

	for (int i = 0; i < 62; i++)
		swap(cardDeck[i], cardDeck[rand() % 62]);
}

bool CardDeck::isEmptyDeck() {
	if (currentCard >= 62)
		return true;
	return false;
}

bool CardDeck::isEmptyDiscardedDeck() {
	if (discardedCards.empty())
		return true;
	return false;
}

Card CardDeck::SelectACardFromDeck() {
	currentCard++;
	return cardDeck[currentCard - 1];
}

Card CardDeck::SelectACardFromDiscardedDeck() {
	if (!discardedCards.empty()) {
		Card c = discardedCards.top();
		discardedCards.pop();
		return c;
	}
}

void CardDeck::discardCard(Card c) {
	discardedCards.push(c);
}