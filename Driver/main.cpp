#include "../Dice/Dice.h"
#include "../Player/Player.h"
#include "../MapLoader/MapLoader.h"
#include "../Lib/GameSetupFunctions.h"
#include <iostream>
#include <string>

int main()
{
  //welcome message
  std::cout << "------------------------------" << std::endl;
  std::cout << "|      KING OF NEW YORK      |" << std::endl;
  std::cout << "|    BY CHRISTIAN PLOURDE    |" << std::endl;
  std::cout << "------------------------------" << std::endl;


  //first we need to determine how many players will be playing the game
  GameSetupFunctions::setNumberOfPlayers();


  MapLoader::setFilePath("D:/C++ Programs/COMP 345/A1/MapLoader/map.map");

  Graph<std::string>* graph = MapLoader::loadMap();

  std::cout << graph -> toString();



  return 0;
}