// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <list.hpp>

TEST(ForwardList, Init) {
  ForwardList list;
  Construct(list);
  EXPECT_EQ(list.Head, nullptr);
  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}

TEST(ForwardList, PushFront) {
  ForwardList list;
  Construct(list);
  PushFront(list, 0);
  PushFront(list, 1);
  PushFront(list, 2);
  PushFront(list, 3);

  ForwardList::Node* node = list.Head;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 3);

  node = node->Next;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 2);

  node = node->Next;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 1);

  node = node->Next;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 0);

  node = node->Next;
  ASSERT_EQ(node, nullptr);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}

TEST(ForwardList, Size) {
  ForwardList list;
  Construct(list);
  PushFront(list, 0);
  PushFront(list, 1);
  PushFront(list, 2);
  PushFront(list, 3);

  EXPECT_EQ(Size(list), 4u);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}

TEST(ForwardList, RemoveAfter) {
  RemoveAfter(nullptr);

  ForwardList list;
  Construct(list);
  PushFront(list, 0);
  RemoveAfter(list.Head);
  EXPECT_EQ(Size(list), 1u);

  PushFront(list, 1);
  PushFront(list, 2);
  PushFront(list, 3);
  EXPECT_EQ(Size(list), 4u);

  RemoveAfter(list.Head);
  EXPECT_EQ(Size(list), 3u);
  ASSERT_NEQ(list.Head, nullptr);
  ASSERT_NEQ(list.Head->Next, nullptr);
  EXPECT_EQ(list.Head->Next->Data, 1);

  RemoveAfter(list.Head->Next);
  EXPECT_EQ(Size(list), 2u);
  ASSERT_NEQ(list.Head, nullptr);
  ASSERT_NEQ(list.Head->Next, nullptr);
  EXPECT_EQ(list.Head->Next->Data, 1);

  RemoveAfter(list.Head->Next);
  EXPECT_EQ(Size(list), 2u);

  RemoveAfter(list.Head);
  EXPECT_EQ(Size(list), 1u);
  ASSERT_NEQ(list.Head, nullptr);
  ASSERT_EQ(list.Head->Next, nullptr);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
  EXPECT_EQ(Size(list), 0u);
}

TEST(ForwardList, PopFront) {
  ForwardList list;
  Construct(list);
  PushFront(list, 0);
  PushFront(list, 1);
  PushFront(list, 2);
  PushFront(list, 3);

  EXPECT_EQ(Size(list), 4u);
  PopFront(list);
  EXPECT_EQ(Size(list), 3u);
  ASSERT_NEQ(list.Head, nullptr);
  EXPECT_EQ(list.Head->Data, 2);

  RemoveAfter(list.Head);
  EXPECT_EQ(Size(list), 2u);
  ASSERT_NEQ(list.Head, nullptr);
  EXPECT_EQ(list.Head->Data, 2);
  ASSERT_NEQ(list.Head->Next, nullptr);
  EXPECT_EQ(list.Head->Next->Data, 0);

  PopFront(list);
  EXPECT_EQ(Size(list), 1u);
  ASSERT_NEQ(list.Head, nullptr);
  EXPECT_EQ(list.Head->Data, 0);

  PopFront(list);
  EXPECT_EQ(Size(list), 0u);
  ASSERT_EQ(list.Head, nullptr);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}

TEST(ForwardList, InsertAfter) {
  ForwardList list;
  Construct(list);
  PushFront(list, 0);
  PushFront(list, 1);
  PushFront(list, 2);
  PushFront(list, 3);

  EXPECT_EQ(Size(list), 4u);

  RemoveAfter(list.Head);
  EXPECT_EQ(Size(list), 3u);
  ASSERT_NEQ(list.Head, nullptr);
  EXPECT_EQ(list.Head->Data, 3);
  ASSERT_NEQ(list.Head->Next, nullptr);
  EXPECT_EQ(list.Head->Next->Data, 1);

  InsertAfter(list->Head, 2);
  EXPECT_EQ(Size(list), 4u);
  ASSERT_NEQ(list.Head, nullptr);
  EXPECT_EQ(list.Head->Data, 3);
  ASSERT_NEQ(list.Head->Next, nullptr);
  EXPECT_EQ(list.Head->Next->Data, 2);

  auto* newNode = InsertAfter(list->Head->Next, -1);
  EXPECT_EQ(Size(list), 5u);
  ASSERT_NEQ(newNode, nullptr);
  EXPECT_EQ(newNode->Data, -1);
  ASSERT_NEQ(newNode->Next, nullptr);
  EXPECT_EQ(newNode->Next->Data, 1);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}

TEST(ForwardList, SomeCases) {
  ForwardList list;
  Construct(list);

  EXPECT_EQ(Size(list), 0u);
  PopFront(list);
  EXPECT_EQ(InsertAfter(nullptr), nullptr);
  RemoveAfter(nullptr);

  EXPECT_EQ(Size(list), 0u);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}

TEST(ForwardList, Reverse) {
  ForwardList list;
  Construct(list);
  PushFront(list, 0);
  PushFront(list, 1);
  PushFront(list, 2);
  PushFront(list, 3);

  EXPECT_EQ(Size(list), 4u);
  Reverse(list);
  EXPECT_EQ(Size(list), 4u);

  ForwardList::Node* node = list.Head;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 0);

  node = node->Next;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 1);

  node = node->Next;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 2);

  node = node->Next;
  ASSERT_NEQ(node, nullptr);
  EXPECT_EQ(node->Data, 3);

  node = node->Next;
  ASSERT_EQ(node, nullptr);

  Destruct(list);
  EXPECT_EQ(list.Head, nullptr);
}
