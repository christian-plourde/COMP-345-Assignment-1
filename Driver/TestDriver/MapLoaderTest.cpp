#include "../../MapLoader/MapLoader.h"
#include <string>

int main()
{
  MapLoader::setFilePath("D:/C++ Programs/COMP 345/A1/MapLoader/map.map");

  std::string t = MapLoader::getFilePath();

  MapLoader::loadMap();
  return 0;
}