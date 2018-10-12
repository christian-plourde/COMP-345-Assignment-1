#ifndef MONSTERDECK_H
#define MONSTERDECK_H
#include "Monsters.h"

class MonsterDeck {
	// class that holds the monster cards
	const static int NUMBER_OF_MONSTERS = 6;			// number of monsters
	private:
		Monsters monsterDeck[NUMBER_OF_MONSTERS];		// array to hold monster

	public:
		MonsterDeck();						// constructor
		~MonsterDeck();						// destructor

		Monsters getMonster(Characters);	// returns monster with Characters enum as name


		void Print();						// print information about each monster
};
#endif