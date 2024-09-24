#pragma once

#include <algorithm>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <iostream>
#include <vector>

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
  void shortestSpan() const;
  void longestSpan() const;
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
