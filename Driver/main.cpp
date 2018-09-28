#include "../Dice/Dice.h"
#include "../Player/Player.h"
#include "../MapLoader/MapLoader.h"
#include <iostream>
#include <string>

int main()
{
  MapLoader::setFilePath("D:/C++ Programs/COMP 345/A1/MapLoader/map.map");

  Graph<std::string>* graph = MapLoader::loadMap();

  std::cout << graph -> toString();



  return 0;
}