#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Card.h"
#include "CardDeck.h"
using namespace std;

int stringToInt(string);
HowTo stringToHowTo(string);
int longestNameSize = 0;

CardDeck::CardDeck() {
	cardDeckList = new SinglyLinkedList<Card>();
	discardedCards = new SinglyLinkedList<Card>();
	string fname = "cards.csv";
	string i, n, c, h, e;
	ifstream file(fname);
	int count = 0;
	if (file) {
		for (int j = 0; j < 2; j++)
		{
			getline(file, i, ',');
			specialCards[j].setID(stringToInt(i));
			getline(file, n, ',');
			specialCards[j].setName(n);
			getline(file, c, ',');
			specialCards[j].setCost(stringToInt(c));
			getline(file, h, ',');
			specialCards[j].setHowTo(stringToHowTo(h));
			getline(file, e);
			specialCards[j].setEffect(e);
			if (n.size() > longestNameSize)
				longestNameSize = n.size();
		}
		while (getline(file, i, ',')) {
			cardDeck[count].setID(stringToInt(i));
			getline(file, n, ',');
			cardDeck[count].setName(n);
			getline(file, c, ',');
			cardDeck[count].setCost(stringToInt(c));
			getline(file, h, ',');
			cardDeck[count].setHowTo(stringToHowTo(h));
			getline(file, e);
			cardDeck[count].setEffect(e);
			count++;
			if (n.size() > longestNameSize)
				longestNameSize = n.size();
		}
		file.close();
	}
	else
		cout << "ERROR: FAILURE TO OPEN FILE";

	Shuffle();
	Shuffle();

	for (int i = 0; i < 64; i++) {
		node<Card> *nodes = new node<Card>();
		nodes -> setData(cardDeck[i]);
		cardDeckList -> add(nodes);
	}
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
		default: return Discard;
	}
}

CardDeck::~CardDeck() {

	delete cardDeckList;
	delete discardedCards;
}

SinglyLinkedList<Card>* CardDeck::getDeck() {
	return cardDeckList;
}

SinglyLinkedList<Card>* CardDeck::getDiscardedDeck() {
	return discardedCards;
}

void CardDeck::Print(SinglyLinkedList<Card> *list) {
	if (list->getCount() == 0)
		cout << "Deck is empty\n";
	else {
		cout << "  ID  |";
		for (int i = 0; i < (longestNameSize-4)/2; i++)
			cout << " ";
		cout << " NAME ";
		for (int i = 0; i < (longestNameSize-4)/2+1; i++)
			cout << " ";
		cout << "|  COST  " << endl;
		node<Card> *n = list->getHead();
		Card c;
		for (int i = 0; i < list->getCount(); i++) {
			c = n->getData();
			int id = c.getID();
			cout << "  ";
			if (id < 10)
				cout << id << "  ";
			else
				cout << id << " ";
			string name = c.getName();
			int size = name.size();
			cout << " | " << name;
			for (int j = size; j <= longestNameSize; j++)
				cout << " ";
			cout << " |   " << c.getCost() << endl;
			n = n->getNext();
		}
	}
}

void CardDeck::Shuffle() {
	srand(time(0));

	for (int i = 0; i < 64; i++)
		swap(cardDeck[i], cardDeck[rand() % 64]);
}

bool CardDeck::isEmptyDeck() {
	if (cardDeckList -> getCount() == 0)
		return true;
	return false;
}

bool CardDeck::isEmptyDiscardedDeck() {
	if (discardedCards -> getCount() == 0)
		return true;
	return false;
}

Card CardDeck::SelectACard(SinglyLinkedList<Card> list) {
	node<Card> *c = list.getHead();
	list.remove(c);
	return c->getData();
}

void CardDeck::discardCard(Card c, SinglyLinkedList<Card> list) {
	node<Card> *n = new node<Card>();
	n->setData(c);
	list.addLast(n);
}