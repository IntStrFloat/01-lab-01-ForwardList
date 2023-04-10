// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <queue.hpp>

TEST(Queue, Init) {
  Queue queue;
  Construct(queue);
  EXPECT_EQ(queue.Head, nullptr);
  EXPECT_EQ(queue.Tail, nullptr);
  Destruct(queue);
  EXPECT_EQ(queue.Head, nullptr);
  EXPECT_EQ(queue.Tail, nullptr);
}

TEST(Queue, Push) {
  Queue queue;
  Construct(queue);
  Push(queue, 0);
  ASSERT_NEQ(queue.Head, nullptr);
  ASSERT_NEQ(queue.Tail, nullptr);
  EXPECT_EQ(queue.Head, queue.Tail);
  Push(queue, 1);
  ASSERT_NEQ(queue.Head, nullptr);
  ASSERT_NEQ(queue.Tail, nullptr);
  EXPECT_EQ(queue.Tail->Data, 1);
  EXPECT_EQ(queue.Head->Data, 0);

  EXPECT_EQ(Pop(queue), 0);
  ASSERT_NEQ(queue.Head, nullptr);
  ASSERT_NEQ(queue.Tail, nullptr);
  EXPECT_EQ(queue.Head, queue.Tail);

  Push(queue, 2);
  Push(queue, 3);
  Push(queue, 4);

  Destruct(queue);
  EXPECT_EQ(queue.Head, nullptr);
  EXPECT_EQ(queue.Tail, nullptr);
}

TEST(Queue, Pop) {
  Queue queue;
  Construct(queue);
  Push(queue, 0);
  ASSERT_NEQ(queue.Head, nullptr);
  ASSERT_NEQ(queue.Tail, nullptr);
  EXPECT_EQ(queue.Head, queue.Tail);
  Push(queue, 1);
  EXPECT_EQ(Pop(queue), 0);
  ASSERT_NEQ(queue.Head, nullptr);
  ASSERT_NEQ(queue.Tail, nullptr);
  EXPECT_EQ(queue.Head, queue.Tail);

  Push(queue, 2);
  Push(queue, 3);
  Push(queue, 4);
  ASSERT_NEQ(queue.Head, nullptr);
  ASSERT_NEQ(queue.Tail, nullptr);
  EXPECT_EQ(Pop(queue), 1);
  EXPECT_EQ(Pop(queue), 2);
  EXPECT_EQ(Pop(queue), 3);
  EXPECT_EQ(Pop(queue), 4);
  Pop(queue);
  EXPECT_TRUE(Empty(queue));

  Destruct(queue);
  EXPECT_EQ(queue.Head, nullptr);
  EXPECT_EQ(queue.Tail, nullptr);
}

TEST(Queue, SomeCases) {
  Queue queue;
  Construct(queue);

  EXPECT_TRUE(Empty(queue));
  Pop(queue);
  EXPECT_TRUE(Empty(queue));

  Destruct(queue);
  EXPECT_EQ(queue.Head, nullptr);
  EXPECT_EQ(queue.Tail, nullptr);
}
