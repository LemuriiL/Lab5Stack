#include <gtest/gtest.h>

#include <Stack1.hpp>
#include <Stack2.hpp>

int getNum() { return 4; }

TEST(FStack, testMove) {
  EXPECT_TRUE(std::is_move_constructible<Stack1 <int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack1 <int>>::value);
}

TEST(FStack, testCopy) {
  EXPECT_FALSE(std::is_copy_constructible<Stack1 <int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack1 <int>>::value);
}

TEST(Sstack, testMove) {
  EXPECT_TRUE(std::is_move_constructible<Stack2 <int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack2 <int>>::value);
}

TEST(Sstack, testCopy) {
  EXPECT_FALSE(std::is_copy_constructible<Stack2 <int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack2 <int>>::value);
}

TEST(FStack, testSize) {
  Stack1<int> stackSize;
  for (int i = 0; i < 10; ++i) stackSize.push(i);
  EXPECT_EQ(stackSize.size(), 10);
}

TEST(FStack, testEmpty) {
  Stack1 <int> emptyStack;
  EXPECT_EQ(emptyStack.empty(), true);
}

TEST(FStack, testHead) {
  Stack1 <int> stackHead;
  stackHead.push(4);
  EXPECT_EQ(stackHead.head(), 4);
}

TEST(FStack, testThrowEmpty) {
  Stack1 <int> emptyStack;
  EXPECT_THROW(emptyStack.head(), std::out_of_range);
}

TEST(FStack, testMove1) {
  Stack1 <int> stackR;
  stackR.push(getNum());
  stackR.push(getNum());
  EXPECT_EQ(stackR.head(), 4);
}

TEST(FStack, testThrow) {
  Stack1 <int> stackThrow;
  EXPECT_THROW(stackThrow.pop(), std::out_of_range);
}