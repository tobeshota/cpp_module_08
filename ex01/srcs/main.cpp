#include "Span.hpp"

int main(void) {
  Span span(5);

  span.addNumber(1);
  span.addNumber(5);
  span.addNumber(10);
  span.addNumber(20);
  span.addNumber(25);
  span.longestSpan();
}
