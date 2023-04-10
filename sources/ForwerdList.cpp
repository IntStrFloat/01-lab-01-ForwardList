// Copyright 2023 by Dmitry Bereznev

#include <iostream>
#include "list.hpp"

void Construct(ForwardList& list) {
  list.Head = nullptr;
}

void Destruct(ForwardList& list) {
  while (list.Head != nullptr) {
    ForwardList::Node* temp = list.Head;
    list.Head = temp->next;
    delete temp;
  }
}

void PopFront(ForwardList& list) {
  if (list.Head == nullptr) {
    return;
  }
  ForwardList::Node* temp = list.Head;
  list.Head = temp->next;
  delete temp;
}

void PushFront(ForwardList& list, int value) {
  ForwardList::Node* temp = new ForwardList::Node;
  temp->value = value;
  temp->next = list.Head;
  list.Head = temp;
}

void RemoveAfter(ForwardList::Node* node) {
  ForwardList::Node *del_elem = new ForwardList::Node;
  if (node->next == nullptr) {
    return;
  }
  del_elem = node->next;
  node->next = del_elem->next;
  delete del_elem;
}

ForwardList::Node* InsertAfter(ForwardList::Node* node, int value) {
  ForwardList::Node* insert_elem = new ForwardList::Node;
  insert_elem->value = value;
  insert_elem->next = node->next;
  node->next = insert_elem;
  return insert_elem;
}

size_t Size(const ForwardList& list){
  size_t cnt = 0;
  ForwardList::Node* temp = const_cast<ForwardList::Node*>(list.Head);
  while (temp != nullptr) {
    cnt++;
    temp = temp->next;
  }
  return cnt;
}

void Reverse(ForwardList& list) {
  ForwardList::Node* temp = nullptr;
  ForwardList::Node* prev = nullptr;
  ForwardList::Node* current = list.Head;
  while (current != nullptr) {
    temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
  }
  list.Head = prev;
}
