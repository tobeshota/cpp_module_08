/**
 * @file easyfindTest.cpp
 * @brief Unit tests for the easyfind function using GoogleTest framework.
 * @details This file contains unit tests that verify the behavior of the
 * easyfind function for finding integers in a container.
 */

#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "easyfind.hpp"

/**
 * @brief Test case to verify if easyfind successfully finds values.
 *
 * @details This test checks that the easyfind function correctly returns an
 * iterator pointing to the found value in a container of integers.
 * It tests various cases where the value exists within the container.
 */
TEST(EasyFindTest, ValueFound) {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  /// Test if easyfind finds the correct value in the container.
  EXPECT_EQ(*easyfind(vec, 3), 3);
  EXPECT_EQ(*easyfind(vec, 1), 1);
  EXPECT_EQ(*easyfind(vec, 5), 5);
}

/**
 * @brief Test case to verify that easyfind throws an exception when a value is
 * not found.
 *
 * @details This test ensures that easyfind throws a std::invalid_argument
 * exception when the requested value is not present in the container.
 */
TEST(EasyFindTest, ValueNotFound) {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  /// Test if easyfind throws an exception for values not found in the
  /// container.
  EXPECT_THROW(easyfind(vec, 6), std::invalid_argument);
  EXPECT_THROW(easyfind(vec, 0), std::invalid_argument);
}

/**
 * @brief Test case to verify that easyfind throws an exception when the
 * container is empty.
 *
 * @details This test ensures that easyfind throws a std::invalid_argument
 * exception when it is called on an empty container.
 */
TEST(EasyFindTest, EmptyContainer) {
  std::vector<int> vec;

  /// Test if easyfind throws an exception for an empty container.
  EXPECT_THROW(easyfind(vec, 1), std::invalid_argument);
}
