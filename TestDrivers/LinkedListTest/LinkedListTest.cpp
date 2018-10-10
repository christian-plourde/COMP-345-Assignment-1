#include "../../Graph/SinglyLinkedList.h"
#include <iostream>

int main()
{
  SinglyLinkedList<int>* list = new SinglyLinkedList<int>();
  node<int> node;
  node.setData(1);

  list -> add(&node);
  std::cout << list -> toString() << std::endl;

  delete list;

  return 0;
}