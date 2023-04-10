// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

struct Queue {
  struct Node {
    Node* Next = nullptr;
    int Data = 0;
  };

  // Указатель на первый элемент очереди.
  Node* Head = nullptr;

  // Указатель на последний элемент очереди.
  Node* Tail = nullptr;
};

void Construct(Queue& queue);
void Destruct(Queue& queue);

void Push(Queue& queue, int value);
int Pop(Queue& queue);
bool Empty(const Queue& queue);

#endif  // INCLUDE_QUEUE_HPP_
