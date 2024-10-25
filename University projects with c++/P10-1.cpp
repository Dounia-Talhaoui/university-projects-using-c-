#include <cstdio>

#include "Doubly_Linked_List.hpp"

void print_list(DoublyLinkedList<int> dll) {
  DLLNode<int>* dlln = dll.begin();
  while (dlln != nullptr) {
    printf("%i, ", (*dlln).cont_);
    dlln = (*dlln).next_;
  }
  printf("\n");
}

void insert(DoublyLinkedList<int>& dll, int value) {
  DLLNode<int>* first_larger = dll.find_first_larger(value);
  if (first_larger != nullptr)
    dll.insert_before(first_larger, value);
  else
    dll.push_back(value);
}

int main() {
  DoublyLinkedList<int> dll;

  insert(dll, 4);
  print_list(dll);
  insert(dll, 5);
  print_list(dll);
  insert(dll, 9);
  print_list(dll);
  insert(dll, 8);
  print_list(dll);
  insert(dll, 6);
  print_list(dll);
  insert(dll, 3);
  print_list(dll);
  insert(dll, 7);
  print_list(dll);
  insert(dll, 2);
  print_list(dll);
  insert(dll, 0);
  print_list(dll);
  insert(dll, 1);
  print_list(dll);

  return 0;
}