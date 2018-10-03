#include "../../Player/Player.h"
#include <iostream>
#include "../../Dice/Dice.h"
#include "../../Graph/Graph.h"
#include "../../MapLoader/MapLoader.h"

int main()
{
  std::cout << "This is a test of the player class." << std::endl;

  Player* player = new Player();
  std::cout << player -> toString() << std::endl;
  player -> rollDice();
  std::cout << "\n";
  std::cout << "\n";

  MapLoader::setFilePath("map.map");
  Graph<std::string>* graph = MapLoader::loadMap();

  player -> move(graph);

  delete graph;
  graph = NULL;
  delete player;
  player = NULL;
}