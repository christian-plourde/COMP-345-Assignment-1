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

  std::cout << "Before move:\n" << player -> toString() << std::endl;

  try
  {
    player -> move(graph);
  }

  catch (MasterNodeFullException e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "After move:\n" << player -> toString() << std::endl;

  delete graph;
  graph = NULL;
  delete player;
  player = NULL;
}