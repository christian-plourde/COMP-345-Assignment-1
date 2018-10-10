#include <iostream>
#include <string>
#include <time.h>
#include "Tile.h"
#include "TileDeck.h"
using namespace std;

TileDeck::TileDeck()
{
	int i = 0;
	currentTile = 0;
	for (i; i < 15; i++) {
		tileDeck[i].setBuilding(HighRise);
		if (i < 5) {
			tileDeck[i].setDurability(1);
			tileDeck[i].setUnit(Infantry);
			tileDeck[i].setReward(1);
		}
		else if (i < 10) {
			tileDeck[i].setDurability(2);
			tileDeck[i].setUnit(Jet);
			tileDeck[i].setReward(2);
		}
		else {
			tileDeck[i].setDurability(3);
			tileDeck[i].setUnit(Tank);
			tileDeck[i].setReward(3);
		}
		tileDeck[i].setRewardType(star);
		tileDeck[i].setisUnit(false);
	}

	for (i; i < 30; i++) {
		tileDeck[i].setBuilding(PowerPlant);
		if (i < 20) {
			tileDeck[i].setDurability(1);
			tileDeck[i].setUnit(Infantry);
			tileDeck[i].setReward(1);
		}
		else if (i < 25) {
			tileDeck[i].setDurability(2);
			tileDeck[i].setUnit(Jet);
			tileDeck[i].setReward(2);
		}
		else {
			tileDeck[i].setDurability(3);
			tileDeck[i].setUnit(Tank);
			tileDeck[i].setReward(3);
		}
		tileDeck[i].setRewardType(energy);
		tileDeck[i].setisUnit(false);
	}

	for (i; i < 45; i++) {
		tileDeck[i].setBuilding(Hospital);
		if (i < 30) {
			tileDeck[i].setDurability(1);
			tileDeck[i].setUnit(Infantry);
			tileDeck[i].setReward(1);
		}
		else if (i < 35) {
			tileDeck[i].setDurability(2);
			tileDeck[i].setUnit(Jet);
			tileDeck[i].setReward(2);
		}
		else {
			tileDeck[i].setDurability(3);
			tileDeck[i].setUnit(Tank);
			tileDeck[i].setReward(3);
		}
		tileDeck[i].setRewardType(heart);
		tileDeck[i].setisUnit(false);
	}
}

TileDeck::~TileDeck() {

}

void TileDeck::Shuffle() {
	srand(time(0));

	for (int i = 0; i < 45; i++)
		swap(tileDeck[i], tileDeck[rand() % 45]);
}

void TileDeck::Print() {
	for (int i = 0; i < 45; i++)
	{
			tileDeck[i].Print();
	}

}

bool TileDeck::EmptyDeck() {
	if (currentTile >= 45)
		return true;
	return false;
}

Tile TileDeck::SelectATile() {
	currentTile++;
	return tileDeck[currentTile - 1];
}

void TileDeck::FlipTile(Tile *t) {

	switch (t->getUnit()) {
	case Infantry: t->setRewardType(heart); break;
	case Jet: t->setRewardType(energy); break;
	case Tank: t->setRewardType(star); break;
	}

	int durability = t->getDurability();
	durability++;
	t->setDurability(durability);

	t->setisUnit(true);
}

void TileDeck::DestroyTile(Tile *t) {
	delete t;
}