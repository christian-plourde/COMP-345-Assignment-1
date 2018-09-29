#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include "../Graph/Graph.h"
#include <string>

//this header file contains the definition for the map loader class, which provides methods for loading map files
//into the game and outputs a graph that contains the data in the map file

class MapLoader
{
  public:
    static Graph<std::string>* loadMap(); //loads a .map file from the passed file path into a graph object
    static void setFilePath(std::string);
    static std::string getFilePath();

  private:
    static bool fileIsValid(); //check if the file at the passed file path is valid or not
    static int nodeCount; //this is required for creating the graph as we need to know how many nodes are in it
    static std::string filePath; //the file path
};

#endif