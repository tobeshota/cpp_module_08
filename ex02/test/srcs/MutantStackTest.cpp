#include <gtest/gtest.h>

#include "MutantStack.hpp"

/**
 * @brief Test suite for the MutantStack class.
 */
class MutantStackTest : public ::testing::Test {
 protected:
  // Create a MutantStack for integers to use in tests
  MutantStack<int> mstack;
};

/**
 * @brief Test that the stack can push and pop elements correctly.
 */
TEST_F(MutantStackTest, PushPopTest) {
  mstack.push(5);
  mstack.push(10);
  EXPECT_EQ(mstack.top(), 10);  // Check that the top element is 10
  mstack.pop();
  EXPECT_EQ(mstack.top(), 5);  // Check that the top element is now 5
  mstack.pop();
  EXPECT_EQ(mstack.size(), 0);  // Check that the stack is empty
}

/**
 * @brief Test that the stack reports its size correctly.
 */
TEST_F(MutantStackTest, SizeTest) {
  EXPECT_EQ(mstack.size(), 0);  // Initially empty
  mstack.push(1);
  EXPECT_EQ(mstack.size(), 1);  // Size should be 1
  mstack.push(2);
  EXPECT_EQ(mstack.size(), 2);  // Size should be 2
  mstack.pop();
  EXPECT_EQ(mstack.size(), 1);  // Size should be 1 after pop
}

/**
 * @brief Test that the stack can iterate over its elements.
 */
TEST_F(MutantStackTest, IterationTest) {
  mstack.push(1);
  mstack.push(2);
  mstack.push(3);

  int expected[] = {1, 2, 3};  // Expected values

  int i = 0;
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    EXPECT_EQ(*it, expected[i++]);  // Check each element
  }
}

/**
 * @brief Test that the stack maintains the correct order of elements.
 */
TEST_F(MutantStackTest, OrderTest) {
  mstack.push(5);
  mstack.push(10);
  mstack.push(15);

  EXPECT_EQ(mstack.top(), 15);  // Last pushed element should be on top
  mstack.pop();
  EXPECT_EQ(mstack.top(), 10);  // Next element should be on top
  mstack.pop();
  EXPECT_EQ(mstack.top(), 5);  // Next element should be on top
}

/**
 * @brief Test copy constructor.
 */
TEST_F(MutantStackTest, CopyConstructorTest) {
  mstack.push(1);
  mstack.push(2);
  mstack.push(3);

  MutantStack<int> copy(mstack);  // Copy constructor
  EXPECT_EQ(copy.size(), 3);      // Size should be the same
  EXPECT_EQ(copy.top(), 3);       // Top should be the same

  copy.pop();
  EXPECT_EQ(copy.size(), 2);    // Size should decrease
  EXPECT_EQ(mstack.size(), 3);  // Original should remain unchanged
}

/**
 * @brief Test copy assignment operator.
 */
TEST_F(MutantStackTest, CopyAssignmentTest) {
  mstack.push(1);
  mstack.push(2);

  MutantStack<int> copy;
  copy = mstack;  // Copy assignment operator

  EXPECT_EQ(copy.size(), 2);  // Size should be the same
  EXPECT_EQ(copy.top(), 2);   // Top should be the same

  copy.pop();
  EXPECT_EQ(copy.size(), 1);    // Size should decrease
  EXPECT_EQ(mstack.size(), 2);  // Original should remain unchanged
}
