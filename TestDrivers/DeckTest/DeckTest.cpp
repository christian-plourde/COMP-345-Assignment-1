#include <iostream>
#include "../../Deck/TileDeck.h"
#include "../../Deck/CardDeck.h"
#include "../../Deck/MonsterDeck.h"
#include "../../Deck/Token.h"
using namespace std;

int main() {

	// CARD DECK TEST
	cout << "CARD DECK TEST" << endl;
	CardDeck decks;
	cout << "INFORMATION ABOUT A CARD: " << endl;
	decks.getDeck()->getHead()->getData().Print();
	cout << endl;
	cout << "PRINTING DISCARDED CARD DECK: " << endl;
	decks.Print(decks.getDiscardedDeck());
	cout << endl;
	cout << "PRINTING CARD DECK: " << endl;
	decks.Print(decks.getDeck());
	cout << endl;
	cout << "DISCARDING CARD" << endl;
	Card c = decks.SelectACard(decks.getDeck());
	decks.discardCard(c, decks.getDiscardedDeck());
	cout << "PRINTING DISCARDED CARD DECK: " << endl;
	decks.Print(decks.getDiscardedDeck());
	cout << endl;
	cout << "PRINTING NEW CARD DECK: " << endl;
	decks.Print(decks.getDeck());
	system("pause");
	system("CLS");

	// MONSTER DECK TEST
	cout << "MONSTER DECK TEST" << endl;
	MonsterDeck monsterDeck;
	monsterDeck.Print();
	/*cout << endl << "UPDATING HEALTH OF CAPTAIN FISH" << endl;
	monsterDeck.getMonster(CaptainFish).setHealth(5);
	monsterDeck.getMonster(CaptainFish).Print();
	monsterDeck.Print();
	cout << endl << "UPDATING VICTORY POINTS OF KONG" << endl;
	monsterDeck.getMonster(Kong).setVictoryPoints(10);
	monsterDeck.getMonster(Kong).Print();*/
	system("pause");
	system("CLS");

	// LOAD MAP FOR TILE DECK TEST
	string filePath = "map.map";
	MapLoader::setFilePath(filePath);
	MapLoader::loadMap();
	system("CLS");

	// TILE DECK TEST
	TileDeck deck;
	deck.Print();
	cout << endl;
	Tile* tile = deck.SelectATile();
	tile->Print();
	cout << endl << "MAKING ABOVE TILE A UNIT TILE" << endl;
	deck.FlipTile(tile);
	tile->Print();
	cout << endl << "DESTROYING ABOVE TILE" << endl;
	deck.DestroyTile(tile);
	tile->Print();
	system("pause");
	system("CLS");

	// TOKEN TEST
	const int NUMBER_OF_TOKENS = 46;
	Token tokens[NUMBER_OF_TOKENS];
	const int NUMBER_OF_WEB = 13;
	const int NUMBER_OF_JINX = 13;
	const int NUMBER_OF_SOUVENIR = 5;
	const int NUMBER_OF_CARAPACE = 15;
	Token t;
	for (int i = 0; i < NUMBER_OF_WEB; i++) {
		t.setName(Web);
		tokens[i] = t;
	}
	for (int i = NUMBER_OF_WEB; i < NUMBER_OF_WEB + NUMBER_OF_JINX; i++) {
		t.setName(Jinx);
		tokens[i] = t;
	}
	for (int i = NUMBER_OF_WEB + NUMBER_OF_JINX; i < NUMBER_OF_WEB + NUMBER_OF_JINX + NUMBER_OF_SOUVENIR; i++) {
		t.setName(Souvenir);
		tokens[i] = t;
	}
	for (int i = NUMBER_OF_WEB + NUMBER_OF_JINX + NUMBER_OF_SOUVENIR; i < NUMBER_OF_WEB + NUMBER_OF_JINX + NUMBER_OF_SOUVENIR + NUMBER_OF_CARAPACE; i++) {
		t.setName(Carapace);
		tokens[i] = t;
	}
	tokens[8].Print();
	tokens[20].Print();
	tokens[29].Print();
	tokens[40].Print();
	system("pause");

	return 0;
}