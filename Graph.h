#include "SinglyLinkedList.h"
#include "GraphVertex.h"
#include <iostream>
#include <cstddef>

//a graph implementation using an adjacency list

template <class T>
class Graph
{
  private:
    int vertexCount; //the number of vertices the graph has
    SinglyLinkedList<T>* adjacencyList[]; //an array of linked lists that will have a position for each vertex and hold a linked list
                                       //containing all the vertices it is adjacent to
    GraphVertex<T>* vertexList[];

  public:
    Graph(int); //constructor in which we pass the number of vertices
    GraphVertex<T>* getVertex(int); //get the vertex at the specified index in the array of vertices
    void display();
};

template <class T>
Graph<T>::Graph(int vertices)
{
  vertexCount = vertices;

  for(int i = 0; i<vertices; i++)
  {
    //create a new linked list and assign it to slot i in the array of adjacencylists
    //create a new vertex and assign it to slot i in the array of vertices

    adjacencyList[i] = new SinglyLinkedList<T>();
    vertexList[i] = new GraphVertex<T>();
    vertexList[i] -> setIndex(i);
  }

}

template <class T>
GraphVertex<T>* Graph<T>::getVertex(int i)
{
  //a method to get the vertex at the specified index in the vertex list array
  return vertexList[i];
}

template <class T>
void Graph<T>::display()
{
  if(vertexCount == 0)
  {
    std::cout << "[]" << std::endl;
  }

  else
  {

  }
}

