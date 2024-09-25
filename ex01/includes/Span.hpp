#pragma once

#include <algorithm>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <iostream>  // for std::numeric_limits<int>::max();
#include <limits>
#include <vector>

/**
 * @brief A class to manage a span of integers with a fixed maximum size.
 *
 * The Span class allows for the storage of a maximum of N integers,
 * and provides functionality to add numbers and calculate the shortest
 * and longest spans between them. It includes exception handling for
 * various edge cases.
 */
class Span {
 private:
  std::vector<int> _vec;
  const unsigned int _N;
  int getRandomInt(void) const;

 public:
  Span();
  Span(unsigned int N);
  Span(const Span& copy);
  Span& operator=(const Span& copy);
  ~Span();

  void addNumber(int num);
  int shortestSpan() const;
  int longestSpan() const;
  void fillSpan();
  class AlreadyFilledException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class EmptyException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class OnlyOneNumberStoredException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};
