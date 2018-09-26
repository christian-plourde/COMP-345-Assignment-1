//the implementation file for the map loader class
#include "MapLoader.h"
#include <fstream>

std::string MapLoader::filePath = ""; //initialize filePath to an empty string
int MapLoader::nodeCount = 0; //initialize the nodeCount to 0

void MapLoader::setFilePath(std::string path)
{
  //method to set the filepath for the map
  MapLoader::filePath = path;
}

std::string MapLoader::getFilePath()
{
  //method to get the filepath of the map
  return MapLoader::filePath;
}

Graph<std::string>* MapLoader::loadMap()
{
  //method to load the map file into a graph object
  if(fileIsValid())
  {
    //if the file was valid then we set up the graph object by reading all of the data in the file and assigning nodes
    std::cout << "Setting up the game board..." << std::endl;

    Graph<std::string>* graph = new Graph<std::string>(MapLoader::nodeCount);

    //we need to reopen the file

    std::ifstream input; //the input stream associated to out file
    input.open(MapLoader::filePath.c_str()); //try opening the file

    //we already know it is valid so we can start reading right away
    std::string line = "";
    std::string nodeName = "";
    int graphIndex = 0;

    //while we still have readable lines
    while(input >> line)
    {
      //first get the name of the node
      if(line == "@node")
      {
        //wipe the nodeName clean
        nodeName = "";

        //if the line is the node declaration
        //then go to the next line and the line after that, where the name field is
        input >> line;
        input >> line;

        //now that we are at the name field we read until we hit the first adjacent node
        while(input >> line && line != "adjacent:")
        {
          nodeName = nodeName + line + " ";
        }

        //since we add a space at the end, we need to trim the right side
        nodeName.erase(nodeName.find_last_not_of(" \n\r\t")+1);
        //now that we have the name of the node, we need to add it to our graph
        graph -> setVertexData(nodeName,graphIndex);

        //now that we have added the name of the node we need to add every node it is adjacent to to its adjacency list
        graphIndex++;
      }
    }

    return graph; //return the graph containing the game board
  }

  else
  {
    //if the file was not valid then we cannot begin the game and we
    //should exit the Program
    std::cerr << "Exiting..." << std::endl;
    exit(1);
    return NULL;
  }

  return NULL;
}

bool MapLoader::fileIsValid()
{
  //method to check if the file is valid

  //before doing anything, check if the file path contains a .map extension
  std::string mapExt = ".map";

  if(filePath.find(mapExt) == std::string::npos)
  {
    std::cerr << "The file requested does not contain a .map extension." << std::endl;
    return false;
  }


  //first we will attempt to open the file

  std::ifstream input; //the input stream associated to out file
  input.open(MapLoader::filePath.c_str()); //try opening the file

  if(!input)
  {
    //if the input file could not be opened, then that means that the input file is not valid
    //therefore close the stream and return false
    input.close();
    std::cerr << "The file at " << filePath << " could not be opened." << std::endl;
    return false;
  }

  //if we passed this point, it means that the file is open

  //we need to check each node to make sure that it is correctly formed
  int nodeCount = 0; //the count of the number of nodes in the file
  int lineNumber = 0; //the line we are at

  //now we need to count the number of times the word "@node" is contained in the file
  std::string line = ""; //the current line being read
  while(input >> line) //while the input stream still has lines to read keep reading
  {
    lineNumber++;
    if(line == "@node") //if the line is equal to "@node", this is the inclusion of another node
    {
      nodeCount++;
      //now we know that we are at the beginning of a node declaration
      //check the next line to see if it is a "{"
      input >> line;
      lineNumber++;
      if(line != "{")
      {
        input.close();
        std::cout << "Missing opening brace in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

      //then check if the line after that contains a name field
      input >> line;
      lineNumber++;
      if(line != "name:")
      {
        input.close();
        std::cout << "Missing node name field in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false; //if the next line does not contain a name field then we return false
      }

      //now we need to make sure that the node has at least one adjacent node to make sure that the graph will be a connected graph
      int adjacentCount = 0;
      while(input >> line && line != "}")
      {
        lineNumber++;
        if(line == "adjacent:")
        {
          adjacentCount ++;
        }
      }

      //if by the end of the loop the adjacent count is still zero, then the file is not valid
      if(adjacentCount == 0)
      {
        input.close();
        std::cout << "No adjacent nodes found in " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

      //now that we have reached the last adjacent node, check if the current line contains a "}"
      if(line != "}")
      {
        input.close();
        std::cout << "Missing closing brace in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

    }

  }

  //if we made it to this point without returning, then that means the file is valid and we return true
  //as long as there is more than one node
  if(nodeCount > 0)
  {
    input.close();
    MapLoader::nodeCount = nodeCount;
    return true;
  }

  //if there was not more than one node, then return false;
  input.close();
  return false;

}
