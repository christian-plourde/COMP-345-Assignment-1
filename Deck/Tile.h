#ifndef TILE_H
#define TILE_H

enum Buildings { HighRise, PowerPlant, Hospital };
enum Units { Infantry, Jet, Tank };
enum Boroughs { Bronx, Queens, Brooklyn, StatenIsland, LowerMan, MidtownMan, UpperMan };
enum Rewards { Star, Heart, Energy };

class Tile
{
private:
	Buildings building;
	Units unit;
	Boroughs borough;
	int durability;
	int reward;
	Rewards rewardType;
	bool isUnit;

public:
	Tile();
	Tile(Buildings, Units, Boroughs, int, int, Rewards, bool);
	~Tile();

	void setBuilding(Buildings);
	void setUnit(Units);
	void setBorough(Boroughs);
	void setDurability(int);
	void setReward(int);
	void setRewardType(Rewards);
	void setisUnit(bool);

	Buildings getBuilding() const;
	Units getUnit() const;
	Boroughs getBorough() const;
	int getDurability() const;
	int getReward() const;
	Rewards getRewardType() const;
	bool getIsUnit() const;

	void Print();
};
#endif