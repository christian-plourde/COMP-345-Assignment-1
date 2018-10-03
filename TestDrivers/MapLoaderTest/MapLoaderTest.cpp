//this is a test of the MapLoader class
#include "../../MapLoader/MapLoader.h"
#include <string>

int main()
{
  //tests compiled in corresponding executables

  //first test with a file that does not exist

  /*
  std::string garbageFilePath = "hello";
  std::cout << "File path: " << garbageFilePath << std::endl;
  MapLoader::setFilePath(garbageFilePath);
  Graph<std::string>* graph = MapLoader::loadMap();
  */

  //second test with a file that is not connected
  /*
  std::string garbageFilePath = "UnconnectedMap.map";
  std::cout << "File path: " << garbageFilePath << std::endl;
  MapLoader::setFilePath(garbageFilePath);
  Graph<std::string>* graph = MapLoader::loadMap();
  */

  //third test where a brace is missing
  /*
  std::string garbageFilePath = "MissingBrace.map";
  std::cout << "File path: " << garbageFilePath << std::endl;
  MapLoader::setFilePath(garbageFilePath);
  Graph<std::string>* graph = MapLoader::loadMap();
  */

  //fourth test where a node has no name
  /*
  std::string garbageFilePath = "MissingNameField.map";
  std::cout << "File path: " << garbageFilePath << std::endl;
  MapLoader::setFilePath(garbageFilePath);
  Graph<std::string>* graph = MapLoader::loadMap();
  */

  //fifth test with a valid map and graph output

  std::string garbageFilePath = "GoodMap.map";
  std::cout << "File path: " << garbageFilePath << std::endl;
  MapLoader::setFilePath(garbageFilePath);
  Graph<std::string>* graph = MapLoader::loadMap();
  std::cout << graph -> toString() << std::endl;
  

  delete graph;
  graph = NULL;


  return 0;
}