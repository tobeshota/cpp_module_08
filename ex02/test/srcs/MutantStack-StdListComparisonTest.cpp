#include <gtest/gtest.h>

#include <list>

#include "MutantStack.hpp"

/**
 * @brief Test that checks if MutantStack's top element matches std::list's back
 * element.
 *
 * This test verifies that after pushing elements to both MutantStack and
 * std::list, the top element of MutantStack matches the back element of
 * std::list, as both should represent the most recently added element.
 */
TEST(MutantStackTest, TopElementComparisonTest) {
  MutantStack<int> mstack;
  std::list<int> llist;

  // Push elements into both containers
  mstack.push(5);
  llist.push_back(5);
  mstack.push(17);
  llist.push_back(17);

  // Check if the top element of MutantStack matches the back element of
  // std::list
  EXPECT_EQ(mstack.top(), llist.back());
}

/**
 * @brief Test that verifies the size of MutantStack and std::list after popping
 * an element.
 *
 * This test checks that after popping the top element from both MutantStack and
 * std::list, their sizes remain identical.
 */
TEST(MutantStackTest, SizeComparisonTest) {
  MutantStack<int> mstack;
  std::list<int> llist;

  // Push elements into both containers
  mstack.push(5);
  llist.push_back(5);
  mstack.push(17);
  llist.push_back(17);

  // Pop the top element from both containers
  mstack.pop();
  llist.pop_back();

  // Check that both containers have the same size
  EXPECT_EQ(mstack.size(), llist.size());
}

/**
 * @brief Test that compares iteration behavior of MutantStack and std::list.
 *
 * This test verifies that MutantStack's iterator can traverse the elements in
 * the same order as std::list's iterator, ensuring that the custom stack
 * behaves correctly as an iterable container.
 */
TEST(MutantStackTest, IteratorComparisonTest) {
  MutantStack<int> mstack;
  std::list<int> llist;

  // Add multiple elements to both containers
  mstack.push(5);
  llist.push_back(5);
  mstack.push(3);
  llist.push_back(3);
  mstack.push(737);
  llist.push_back(737);
  mstack.push(0);
  llist.push_back(0);

  // Test iteration: Compare elements in MutantStack and std::list using
  // iterators
  MutantStack<int>::iterator mit = mstack.begin();
  std::list<int>::iterator lit = llist.begin();

  // Iterate through both containers and compare each element
  while (mit != mstack.end() && lit != llist.end()) {
    EXPECT_EQ(*mit, *lit);  // Ensure that each element is the same
    ++mit;
    ++lit;
  }

  // Ensure both iterators reached the end
  EXPECT_EQ(mit, mstack.end());
  EXPECT_EQ(lit, llist.end());
}
