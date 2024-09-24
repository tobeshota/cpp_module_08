#include "Span.hpp"

Span::Span() : _N(0) {
  std::cout << "(constructor) Span Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
  std::cout << "(constructor) Span constructor called" << std::endl;
}

Span::Span(const Span& copy) : _N(copy._N) {
  std::cout << "(constructor) Span copy constructor called" << std::endl;
  *this = copy;
}

Span& Span::operator=(const Span& copy) {
  if (this != &copy) {
    this->_vec = copy._vec;
  }
  return *this;
}

Span::~Span() {
  std::cout << "(destructor)Span destructor called" << std::endl;
}

void Span::addNumber(int num) {
  if (_vec.size() >= _N) throw AlreadyFilledException();
  _vec.push_back(num);
}

void Span::shortestSpan() const {
  if (_vec.size() == 0)
    throw EmptyException();
  else if (_vec.size() == 1)
    throw OnlyOneNumberStoredException();
  std::vector<int> copyVec = _vec;
  std::sort(copyVec.begin(), copyVec.end());
  int minSpan = std::numeric_limits<int>::max();
  for (std::vector<int>::iterator it = copyVec.begin() + 1; it != copyVec.end();
       it++) {
    int span = *it - *(it - 1);
    minSpan = (span <= minSpan) ? span : minSpan;
  }
  std::cout << minSpan;
}

void Span::longestSpan() const {
  if (_vec.size() == 0)
    throw EmptyException();
  else if (_vec.size() == 1)
    throw OnlyOneNumberStoredException();
  std::vector<int> copyVec = _vec;
  std::sort(copyVec.begin(), copyVec.end());
  std::cout << copyVec.back() - copyVec.front();
}

int Span::getRandomInt(void) const {
  std::srand(std::time(0));
  return std::rand();
}

void Span::fillSpan() {
  for (unsigned int i = 0; i < _N; i++) {
    _vec.push_back(this->getRandomInt());
  }
}

const char* Span::AlreadyFilledException::what() const throw() {
  return "vector in already filled";
}

const char* Span::EmptyException::what() const throw() {
  return "vector in empty";
}

const char* Span::OnlyOneNumberStoredException::what() const throw() {
  return "vector size is only 1";
}
