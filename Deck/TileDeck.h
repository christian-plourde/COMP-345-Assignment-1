#ifndef TILEDECK_H
#define TILEDECK_h

#include "Tile.h"

class TileDeck
{
	private:
		Tile tileDeck[45];
		int currentTile;

	public:
		TileDeck();
		~TileDeck();

		void Print();
		void Shuffle();
		bool EmptyDeck();
		Tile SelectATile();
		void FlipTile(Tile*);
		void DestroyTile(Tile*);
};
#endif