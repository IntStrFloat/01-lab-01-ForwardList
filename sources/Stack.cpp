// Copyright 2023 by Dmitry Bereznev

#include <iostream>
#include "stack.hpp"


void Construct(Stack& stack) {
  stack.Top = nullptr;
}

bool Empty(const Stack& stack) {
  return stack.Top == nullptr;
}

int Pop(Stack& stack) {
  if (Empty(stack)) {
    return 0;
  }
  int data = stack.Top->Data;
  Stack::Node* temp = stack.Top;
  stack.Top = stack.Top->Next;
  delete temp;
  return data;
}

void Destruct(Stack& stack) {
  while (!Empty(stack)) {
    Pop(stack);
  }
  stack.Top = nullptr;
}

void Push(Stack& stack, int value) {
  Stack::Node* new_node = new Stack::Node;
  new_node->Data = value;
  new_node->Next = stack.Top;
  stack.Top = new_node;
}
