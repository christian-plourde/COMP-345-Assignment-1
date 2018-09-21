#include "SinglyLinkedList.h"
#include <vector>
#include "GraphVertex.h"
#include "SinglyLinkedListNode.h"
#include <iostream>
#include <cstddef>

//a graph implementation using an adjacency list

template <class T>
class Graph
{
  private:
    int vertexCount; //the number of vertices the graph has
    SinglyLinkedList<T>* adjacencyList; //an array of linked lists that will have a position for each vertex and hold a linked list
                                          //containing all the vertices it is adjacent to
    GraphVertex<T>* vertexList;

  public:
    Graph(int); //constructor in which we pass the number of vertices
    GraphVertex<T>* getVertex(int); //get the vertex at the specified index in the array of vertices
    SinglyLinkedList<T>* getNeighbors(int); //get the neighbors of the vertex at the index passed to the function
    void display(); //method to display the graph's contents to the console
};

template <class T>
Graph<T>::Graph(int vertices)
{
  vertexCount = vertices;
  //we need to allocate the memory for the two arrays
  adjacencyList = new SinglyLinkedList<T>[vertices];
  vertexList = new GraphVertex<T>[vertices];

  for(int i = 0; i<vertexCount; i++)
  {
    //set the index of each vertex in the list to i
    vertexList[i].setIndex(i);
  }
}

template <class T>
SinglyLinkedList<T>* Graph<T>::getNeighbors(int i)
{
  SinglyLinkedList<T> * listPtr = &adjacencyList[i];
  return listPtr;
}

template <class T>
GraphVertex<T>* Graph<T>::getVertex(int i)
{
  //a method to get the vertex at the specified index in the vertex list array
    GraphVertex<T> * vertexPtr = &vertexList[i];
    return vertexPtr;
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
    for(int i = 0; i < vertexCount; i++)
    {
      std::cout << vertexList[i].getData() << " -> ";
      adjacencyList[i].display();
    }
  }
}

