#ifndef TILE_H
#define TILE_H

#include "../MapLoader/MapLoader.h" //required for the zones

enum Buildings { HighRise, PowerPlant, Hospital };
enum Units { Infantry, Jet, Tank };
enum Rewards { star, heart, energy };

class Tile
{
private:
	Buildings building;
	Units unit;
	int zone;
	int durability;
	int reward;
	Rewards rewardType;
	bool isUnit;

public:
	Tile();
	Tile(Buildings, Units, int, int, int, Rewards, bool);
	~Tile();

	void setBuilding(Buildings);
	void setUnit(Units);
	void setZone(int);
	void setDurability(int);
	void setReward(int);
	void setRewardType(Rewards);
	void setisUnit(bool);

	Buildings getBuilding() const;
	Units getUnit() const;
	int getZone() const;
	int getDurability() const;
	int getReward() const;
	Rewards getRewardType() const;
	bool getIsUnit() const;

	void Print();
};
#endif