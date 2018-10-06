#include "../../Player/Player.h"
#include <iostream>
#include "../../Dice/Dice.h"
#include "../../Graph/Graph.h"
#include "../../MapLoader/MapLoader.h"

int main()
{
  std::cout << "This is a test of the player class." << std::endl;

  Player* player = new Player();
  Player* player2 = new Player();
  std::cout << player -> toString() << std::endl;
  std::cout << player2 -> toString() << std::endl;
  player -> rollDice();
  std::cout << "\n";
  std::cout << "\n";

  MapLoader::setFilePath("map.map");
  MapLoader::loadMap();

  player -> resolveDice();




  delete player;
  player = NULL;
}