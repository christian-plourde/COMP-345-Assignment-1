#include "../Graph/Graph.h"
#include "../Dice/Dice.h"
#include "../Player/Player.h"
#include <iostream>
#include <string>

int main()
{
  //a graph of ten vertices
  Graph<int>* graph = new Graph<int>(10);

  GraphVertex<int>* v1 = graph -> getVertex(0);
  node<int>* n1 = new node<int>();
  n1 -> setData(3);
  SinglyLinkedList<int>* l1 = graph -> getNeighbors(0);
  l1 -> add(n1);
  v1 -> setData(3);

  for(int i = 0; i<graph -> getVertexCount(); i++)
  {
    graph -> setVertexData(i,i);
    graph -> addNeighbor(i,i);
    graph -> addNeighbor(4,i);
  }

  std::cout << graph -> toString();

  Dice* d1 = new Dice();


  d1 -> roll();
  std::cout << d1 -> toString() << std::endl;
  Player* player1 = new Player("Chris");
  player1 -> setCharacter(Sheriff);
  std::cout << player1 -> toString() << std::endl;
  Player* player2 = new Player("Dan");
  player2 -> setCharacter(CaptainFish);
  std::cout << player2 -> toString() << std::endl;

  for(int i = 0; i<6; i++)
  {
    enum Characters* chars = Player::getChosenCharacters();
    std::cout << chars[i] << std::endl;
  }



  return 0;
}