#include <iostream>
#include <cstddef>
#include "SinglyLinkedListNode.h"

template <class T>
class SinglyLinkedList
{

  private:
    node<T> *head; //the first node in the list
    int count; //the count of items in the list

  public:
    SinglyLinkedList(); //constructor
    void add(node<T>*); //add a node to the list
    void remove(node<T>*); //remove a node from the list
    node<T>* search(node<T>*); //search the list for a particular node
    bool contains(node<T>*); //determines if the passed node is in the list
    void clear(); //clears all the elements in the list 
    void display(); //display the linked list's contents

};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  head = NULL; //set the head of the list to point at nothing
  count = 0; //initially there are no items in the list
}

template <class T>
void SinglyLinkedList<T>::add(node<T>* newNode)
{
  //if there are no elements in the list, just point the head to our node
  if(count == 0)
    head = newNode;

  else
  {
    //otherwise we need to point the new node to the current head
    newNode -> setNext(head);
    head = newNode;
  }

  //increase the size of the list by one
  count++;
}

template <class T>
void SinglyLinkedList<T>::remove(node<T>* toRemove)
{
  //first check if the passed node is contained in the list
  if(this -> contains(toRemove))
  {
    //if the node is in the list we need to remove it
    //start at the head
    node<T>* currentNode = head;

    //if the node to remove is the head, then we just set the head to the next node after the head
    //and delete the pointer to remove

    if(head == toRemove)
    {
      //move the currentNode to the next node
      currentNode = currentNode -> getNext();
      //set the head to the currentNode, which is the second node in the list
      head = currentNode;
      //decrease the count by one
      count--;
      //delete the pointer to the old head
      delete toRemove;
      toRemove = NULL;
      return;
    }

    //if our node is not the head
    int i = 0;
    for(i = 0; i<count; i++)
    {

      if(currentNode -> getNext() == toRemove)
      {

        //if the next node is the one we want to remove, set the next of the node we are at to the next of the node to remove
        currentNode -> setNext(toRemove -> getNext());

        //delete the node to remove
        delete toRemove;
        toRemove = NULL;
        //decrease count by one and return
        count--;
        return;
      }

      //move down the list
      currentNode = currentNode -> getNext();
    }
  }

  else
  {
    //otherwise we have nothing to do
    return;
  }
}

template <class T>
node<T>* SinglyLinkedList<T>::search(node<T>* toFind)
{
  //a method that will search for a passed node in the list and will return null if the node is not found
  if(count == 0)
  {
    return NULL;
  }

  else
  {
    //start at the head
    node<T>* currentNode = head;

    int i = 0;

    for(i = 0; i<count; i++)
    {
      //for each element in the list, check if the pointers are equal.
      if(currentNode == toFind)
      {
        //if they point to the same object, return true
        return currentNode;
      }

      else
      {
        //otherwise, move the currentNode to the next node
        currentNode = currentNode -> getNext();
      }
    }

    //if we exit the loop it means it was not found
    return NULL;
  }

}

template <class T>
void SinglyLinkedList<T>::clear()
{
  //method to clear everything in the linked list
  node<T>* currentNode = head;
  node<T>* next;
  while(currentNode != NULL)
  {
    //set the next pointer to the next node in the list
    next = currentNode -> getNext();
    //delete the pointer to the node we are at
    delete currentNode;
    //then move to the next node
    currentNode = next;
  }

  //delete the real head pointer  and set it to null and make the count 0
  delete head;
  head = NULL;
  count = 0;
}

template <class T>
bool SinglyLinkedList<T>::contains(node<T>* toFind)
{
  if(count == 0)
  {
    return false;
  }

  else
  {
    //start at the head
    node<T>* currentNode = head;

    int i = 0;

    for(i = 0; i<count; i++)
    {
      //for each element in the list, check if the pointers are equal.
      if(currentNode == toFind)
      {
        //if they point to the same object, return true
        return true;
      }

      else
      {
        //otherwise, move the currentNode to the next node
        currentNode = currentNode -> getNext();
      }
    }

    //if we exit the loop it means it was not found
    return false;
  }

}

template <class T>
void SinglyLinkedList<T>::display()
{
  if(count == 0)
    std::cout << "[]" << std::endl;

  else
  {
    //start at the head of the list.
    node<T> *currentNode = head;
    std::cout << "[";

    int i = 0;

    for(i = 0; i<count; i++)
    {
      if(i == count - 1)
      {
        std::cout << currentNode -> getData();
      }

      else
      {
        std::cout << currentNode -> getData() << ", ";
      }

      currentNode = currentNode -> getNext();
    }

    std::cout << "]" <<std::endl;
  }

}
