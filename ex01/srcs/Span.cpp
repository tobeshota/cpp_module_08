#include "Span.hpp"
/**
 * @brief Default constructor for the Span class.
 *
 * Initializes a Span object with zero maximum size (N).
 */
Span::Span() : _N(0) {
  std::cout << "(constructor) Span Default constructor called" << std::endl;
}

/**
 * @brief Constructor for the Span class with a specified maximum size.
 *
 * @param N An unsigned integer representing the maximum number of integers
 *          that can be stored in the Span.
 */
Span::Span(unsigned int N) : _N(N) {
  std::cout << "(constructor) Span constructor called" << std::endl;
}

/**
 * @brief Copy constructor for the Span class.
 *
 * Initializes a new Span object as a copy of an existing Span object.
 *
 * @param copy The Span object to be copied.
 */
Span::Span(const Span& copy) : _N(copy._N) {
  std::cout << "(constructor) Span copy constructor called" << std::endl;
  *this = copy;
}

/**
 * @brief Assignment operator for the Span class.
 *
 * Assigns the values of one Span object to another.
 *
 * @param copy The Span object to copy values from.
 * @return A reference to the current object after assignment.
 */
Span& Span::operator=(const Span& copy) {
  if (this != &copy) {
    this->_vec = copy._vec;
  }
  return *this;
}

/**
 * @brief Destructor for the Span class.
 *
 * Cleans up resources when a Span object is destroyed.
 */
Span::~Span() {
  std::cout << "(destructor)Span destructor called" << std::endl;
}

/**
 * @brief Adds a number to the Span.
 *
 * This function adds an integer to the collection. If the collection has
 * already reached its maximum size (N), an AlreadyFilledException is thrown.
 *
 * @param num The integer to be added to the Span.
 * @throw AlreadyFilledException if the Span is already filled.
 */
void Span::addNumber(int num) {
  if (_vec.size() >= _N) throw AlreadyFilledException();
  _vec.push_back(num);
}

/**
 * @brief Computes the shortest span between any two numbers in the Span.
 *
 * This function finds the smallest difference between any two integers in the
 * collection. If there are no numbers or only one number stored, it throws an
 * EmptyException or OnlyOneNumberStoredException respectively.
 *
 * @throw EmptyException if there are no numbers stored.
 * @throw OnlyOneNumberStoredException if there is only one number stored.
 * @return The shortest span as an integer.
 */
int Span::shortestSpan() const {
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
  return minSpan;
}

/**
 * @brief Computes the longest span between the maximum and minimum numbers in
 * the Span.
 *
 * This function calculates the difference between the largest and smallest
 * integers in the collection. If there are no numbers or only one number
 * stored, it throws an EmptyException or OnlyOneNumberStoredException
 * respectively.
 *
 * @throw EmptyException if there are no numbers stored.
 * @throw OnlyOneNumberStoredException if there is only one number stored.
 * @return The longest span as an integer.
 */
int Span::longestSpan() const {
  if (_vec.size() == 0)
    throw EmptyException();
  else if (_vec.size() == 1)
    throw OnlyOneNumberStoredException();
  std::vector<int> copyVec = _vec;
  std::sort(copyVec.begin(), copyVec.end());
  return copyVec.back() - copyVec.front();
}

/**
 * @brief Generates a random integer.
 *
 * This function generates and returns a random integer using the standard
 * random number generator. It seeds the generator with the current time.
 *
 * @return A random integer.
 */
int Span::getRandomInt(void) const {
  std::srand(std::time(0));
  return std::rand();
}

/**
 * @brief Fills the Span with random integers.
 *
 * This function populates the Span with random integers by calling
 * getRandomInt(). It will add up to the maximum size (N) defined for the Span.
 */
void Span::fillSpan() {
  for (unsigned int i = 0; i < _N; i++) {
    _vec.push_back(this->getRandomInt());
  }
}

/**
 * @brief Exception message for when the Span is already filled.
 *
 * @return A const char pointer to the exception message.
 */
const char* Span::AlreadyFilledException::what() const throw() {
  return "vector in already filled";
}

/**
 * @brief Exception message for when the Span is empty.
 *
 * @return A const char pointer to the exception message.
 */
const char* Span::EmptyException::what() const throw() {
  return "vector in empty";
}

/**
 * @brief Exception message for when only one number is stored in the Span.
 *
 * @return A const char pointer to the exception message.
 */
const char* Span::OnlyOneNumberStoredException::what() const throw() {
  return "vector size is only 1";
}
