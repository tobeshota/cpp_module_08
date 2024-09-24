#include <gtest/gtest.h>

#include <algorithm>
#include <limits>
#include <vector>

#include "Span.hpp"

/**
 * @brief Test case to check basic functionality of the addNumber method.
 * This test adds numbers to a Span instance and checks that an exception
 * is thrown when trying to add more numbers than the defined capacity (N).
 */
TEST(SpanTest, AddNumber) {
  Span span(5);

  span.addNumber(1);
  span.addNumber(2);
  span.addNumber(3);
  span.addNumber(4);
  span.addNumber(5);

  // Adding more than 5 numbers should throw an exception
  EXPECT_THROW(span.addNumber(6), Span::AlreadyFilledException);
}

/**
 * @brief Test case to check the functionality of the shortestSpan method.
 * This test adds a series of numbers and ensures the shortest span between
 * them is calculated correctly.
 */
TEST(SpanTest, ShortestSpan) {
  Span span(5);

  span.addNumber(1);
  span.addNumber(5);
  span.addNumber(10);
  span.addNumber(20);
  span.addNumber(25);

  // The shortest span should be 5 - 1 = 4
  EXPECT_EQ(span.shortestSpan(), 4);
}

/**
 * @brief Test case to check the functionality of the longestSpan method.
 * This test verifies that the longest span between numbers is calculated
 * correctly.
 */
TEST(SpanTest, LongestSpan) {
  Span span(5);

  span.addNumber(1);
  span.addNumber(5);
  span.addNumber(10);
  span.addNumber(20);
  span.addNumber(25);

  // The longest span should be 25 - 1 = 24
  EXPECT_EQ(span.longestSpan(), 24);
}

/**
 * @brief Test case to verify that an exception is thrown if the span is
 * calculated when the Span instance is empty.
 */
TEST(SpanTest, EmptyException) {
  Span span(5);

  // When no numbers are added, calling shortestSpan or longestSpan should throw
  // an exception
  EXPECT_THROW(span.shortestSpan(), Span::EmptyException);
  EXPECT_THROW(span.longestSpan(), Span::EmptyException);
}

/**
 * @brief Test case to verify that an exception is thrown when there is only one
 * number stored in the Span instance. Span calculation requires at least two
 * numbers.
 */
TEST(SpanTest, OnlyOneNumberStoredException) {
  Span span(5);

  span.addNumber(1);
  // With only one number, calling shortestSpan or longestSpan should throw an
  // exception
  EXPECT_THROW(span.shortestSpan(), Span::OnlyOneNumberStoredException);
  EXPECT_THROW(span.longestSpan(), Span::OnlyOneNumberStoredException);
}

/**
 * @brief Test case to verify that the fillSpan method works correctly.
 * The Span instance is filled with a large number of random integers,
 * and it should successfully calculate both shortest and longest spans.
 */
TEST(SpanTest, FillSpan) {
  Span span(10000);

  span.fillSpan();

  // The filled Span should have valid shortestSpan and longestSpan
  EXPECT_NO_THROW(span.shortestSpan());
  EXPECT_NO_THROW(span.longestSpan());
}

/**
 * @brief Test case to verify that the copy constructor and assignment operator
 * function correctly. The copied or assigned Span should retain the same
 * state as the original.
 */
TEST(SpanTest, CopyConstructorAndAssignment) {
  Span span1(5);

  span1.addNumber(1);
  span1.addNumber(2);
  span1.addNumber(3);
  span1.addNumber(4);
  span1.addNumber(5);

  // Copy constructor test
  Span span2(span1);
  EXPECT_NO_THROW(span2.shortestSpan());
  EXPECT_NO_THROW(span2.longestSpan());

  // Assignment operator test
  Span span3(5);
  span3 = span1;
  EXPECT_NO_THROW(span3.shortestSpan());
  EXPECT_NO_THROW(span3.longestSpan());
}
