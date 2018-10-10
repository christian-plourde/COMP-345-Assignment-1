#include "Tile.h"
#include<iostream>
#include<string>
using namespace std;

string Build[3] = { "High-Rise", "Power Plant", "Hospital" };
string Unit[3] = { "Infantry", "Jet", "Tank" };
string Reward[3] = { "Star", "Heart", "Energy" };

Tile::Tile() {
	building = HighRise;
	unit = Infantry;
	zone = 0;
	durability = 1;
	reward = 1;
	rewardType = star;
	isUnit = false;
}

Tile::Tile(Buildings bu, Units un, int zone, int dur, int rew, Rewards rewType, bool isUn) {
	building = bu;
	unit = un;
	this -> zone = zone;
	durability = dur;
	reward = rew;
	rewardType = rewType;
	isUnit = isUn;
}

Tile::~Tile() {
	delete this;
}

void Tile::setBuilding(Buildings build) {
	building = build;
}

void Tile::setUnit(Units uni) {
	unit = uni;
}

void Tile::setZone(int zone) {

	if(zone >= 0 && zone < MapLoader::getMap() -> getVertexCount())
	{
		this -> zone = zone;
	}
}

void Tile::setDurability(int dur) {
	durability = dur;
}

void Tile::setReward(int rew) {
	reward = rew;
}

void Tile::setRewardType(Rewards rewType) {
	rewardType = rewType;
}

void Tile::setisUnit(bool type) {
	isUnit = type;
}

Buildings Tile::getBuilding() const {
	return building;
}

Units Tile::getUnit() const {
	return unit;
}

int Tile::getZone() const {
	return zone;
}

int Tile::getDurability() const {
	return durability;
}

int Tile::getReward() const {
	return reward;
}

Rewards Tile::getRewardType() const {
	return rewardType;
}

bool Tile::getIsUnit() const {
	return isUnit;
}

void Tile::Print() {
	cout << "{ Building: " << Build[building] << endl;
	cout << "  Unit: " << Unit[unit] << endl;
	cout << "  Borough: " << MapLoader::getMap() -> getVertex(zone) -> toString() << endl;
	cout << "  Durability: " << durability << endl;
	if (reward > 1)
		cout << "  Reward: " << reward << " " << Reward[rewardType] << "s\n";
	else
		cout << "  Reward: " << reward << " " << Reward[rewardType] << endl;
	cout << " Unit Tile: " << isUnit << " }" << endl;
}