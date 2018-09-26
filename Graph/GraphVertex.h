#ifndef GRAPHVERTEX_H
#define GRAPHVERTEX_H

#include <iostream>
#include <string>
#include "../Lib/StringFunctions.h"

template <class T>
class GraphVertex
{
  //a class for the vertices of the graph data structure
  private:
    int index; //the vertices index in the graph's array
    T data; //the data stored in the vertex

  public:
    GraphVertex(); //constructor
    ~GraphVertex(); //destructor
    int getIndex(); //returns the index of the vertex in the graph's array
    void setIndex(int); //change the index of the vertex in the graph's array
    T getData(); //get the data stored in the vertex
    void setData(T); //set the data stored in the vertex
    std::string toString(); //displays the data stored in the vertex
};

template <class T>
GraphVertex<T>::GraphVertex()
{
  //constructor
}

template <class T>
GraphVertex<T>::~GraphVertex()
{
  //destructor
}

template <class T>
int GraphVertex<T>::getIndex()
{
  return index;
}

template <class T>
void GraphVertex<T>::setIndex(int newIndex)
{
  index = newIndex;
}

template <class T>
T GraphVertex<T>::getData()
{
  return data;
}

template <class T>
void GraphVertex<T>::setData(T newData)
{
  data = newData;
}

template <class T>
std::string GraphVertex<T>::toString()
{
  std::string output = "";
  output += libString::to_string(data);
  return output;
}

#endif