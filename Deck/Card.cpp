#include <iostream>
#include "Card.h"

string how_To[4] = { "Empty", "Goal", "Keep", "Discard" };

Card::Card() {
	name = "";
	cost = -1;
	howTo = Empty;
	effect = "";
}

Card::Card(string nam, int cos, HowTo how, string eff) {
	name = nam;
	cost = cos;
	howTo = how;
	effect = eff;
}

Card::~Card() {
	//delete this;
}

void Card::setName(string nam) {
	name = nam;
}

void Card::setCost(int cos) {
	cost = cos;
}

void Card::setHowTo(HowTo how) {
	howTo = how;
}

void Card::setEffect(string eff) {
	effect = eff;
}

string Card::getName() const {
	return name;
}

int Card::getCost() const {
	return cost;
}

HowTo Card::getHowTo() const {
	return howTo;
}

string Card::getEffect() const {
	return effect;
}

void Card::Print() {
	cout << "{ Name: " << name << endl;
	cout << "  Cost: " << cost << endl;
	cout << "  How To Play: " << how_To[howTo] << endl;
	cout << "  Effect: " << effect << endl;
}