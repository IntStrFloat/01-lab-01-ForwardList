// Copyright 2023 by Dmitry Bereznev

#include <iostream>
#include "queue.hpp"

void Construct(Queue& queue) {
  queue.Head = nullptr;
  queue.Tail = nullptr;
}

void Destruct(Queue& queue) {
  Queue::Node* temp = new Queue::Node;

  while (queue.Tail != nullptr) {
    temp = queue.Tail;
    queue.Tail = queue.Tail->Next;
    delete temp;
  }
}
bool Empty(const Queue& queue) {
  return queue.Head == nullptr && queue.Tail == nullptr;
}
int Pop(Queue& queue)
{
  if (Empty(queue)) {
    return 0;
  }
  int result = queue.Head->Data;
  Queue::Node* old_head = queue.Head;
  queue.Head = queue.Head->Next;
  delete old_head;

  return result;
}

void Push(Queue& queue, int value) {
  Queue::Node* new_node = new Queue::Node;
  new_node->Data = value;
  new_node->Next = nullptr;
  if (queue.Head == nullptr) {
    queue.Head = new_node;
    queue.Tail = new_node;
  }
  queue.Tail->Next = new_node;
  queue.Tail = new_node;
}
