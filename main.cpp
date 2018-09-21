#include "Graph/Graph.h"
#include "Dice/Dice.h"


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

  graph -> display();

  Dice* d1 = new Dice();


  d1 -> roll();
  d1 -> display();



  return 0;
}