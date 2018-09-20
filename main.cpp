#include "Graph.h"

int main()
{
  //a graph of ten vertices
  Graph<int>* graph = new Graph<int>(10);

  graph -> display();
  return 0;
}