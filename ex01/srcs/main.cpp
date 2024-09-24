#include <iostream>

#include "Span.hpp"

/**
 * @brief Main function to demonstrate the functionality of the Span class.
 *
 * This program creates an instance of the Span class with a specified maximum
 * size (N) and populates it with random integers. It showcases the usage of the
 * `addNumber`, `shortestSpan`, and `longestSpan` methods, handling exceptions
 * that may arise. The output displays the shortest and longest spans calculated
 * from the stored integers.
 *
 * @return Exit status of the program.
 */
int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;  // expect: 2
  std::cout << sp.longestSpan() << std::endl;   // expect: 14
  return 0;
}
