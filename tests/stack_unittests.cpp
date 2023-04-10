// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <stack.hpp>

TEST(Stack, Init) {
  Stack stack;
  Construct(stack);
  EXPECT_EQ(stack.Top, nullptr);
  Destruct(stack);
  EXPECT_EQ(stack.Top, nullptr);
}

TEST(Stack, Push) {
  Stack stack;
  Construct(stack);
  Push(stack, 0);
  ASSERT_NEQ(stack.Top, nullptr);
  Push(stack, 1);
  EXPECT_FALSE(Empty(stack));
  EXPECT_EQ(Pop(stack), 1);
  ASSERT_NEQ(stack.Top, nullptr);

  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);

  EXPECT_FALSE(Empty(stack));
  Destruct(stack);
  EXPECT_EQ(stack.Top, nullptr);
  EXPECT_EQ(stack.Tail, nullptr);
  EXPECT_TRUE(Empty(stack));
}

TEST(Stack, Pop) {
  Stack stack;
  Construct(stack);

  Push(stack, 0);
  EXPECT_FALSE(Empty(stack));
  ASSERT_NEQ(stack.Top, nullptr);

  Push(stack, 1);
  EXPECT_FALSE(Empty(stack));
  EXPECT_EQ(Pop(stack), 1);
  ASSERT_NEQ(stack.Top, nullptr);

  Push(stack, 2);
  Push(stack, 3);
  Push(stack, 4);
  EXPECT_FALSE(Empty(stack));
  ASSERT_NEQ(stack.Top, nullptr);
  EXPECT_EQ(Pop(stack), 4);
  EXPECT_EQ(Pop(stack), 3);
  EXPECT_EQ(Pop(stack), 2);
  EXPECT_EQ(Pop(stack), 0);
  EXPECT_TRUE(Empty(stack));
  Pop(stack);
  EXPECT_TRUE(Empty(stack));

  Destruct(stack);
  EXPECT_EQ(stack.Top, nullptr);
}

TEST(Stack, SomeCases) {
  Stack stack;
  Construct(stack);

  EXPECT_TRUE(Empty(stack));
  Pop(stack);
  EXPECT_TRUE(Empty(stack));

  Destruct(stack);
  EXPECT_EQ(stack.Top, nullptr);
}
