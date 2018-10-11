#ifndef TILEDECK_H
#define TILEDECK_h

#include "Tile.h"
#include <cstdlib>

class TileDeck
{
	private:
		static Tile tileDeck[];
		int currentTile;

	public:
		TileDeck();
		~TileDeck();
		void Print();
		void Shuffle();
		bool EmptyDeck();
		static Tile* getTileDeck();
		Tile* SelectATile();
		Tile* getTile(int);
		void FlipTile(Tile*);
		void DestroyTile(Tile*);
};
#endif