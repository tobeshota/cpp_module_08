#pragma once
#include <iostream>
#include <stack>

/**
 * @brief MutantStack is an iterable stack class that extends std::stack.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class MutantStack : public std::stack<T> {
 public:
  /**
   * @brief Default constructor.
   */
  MutantStack() : std::stack<T>() {}

  /**
   * @brief Copy constructor.
   *
   * @param other The MutantStack object to copy from.
   */
  MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

  /**
   * @brief Copy assignment operator.
   *
   * @param other The MutantStack object to copy from.
   * @return MutantStack& Reference to the current object.
   */
  MutantStack& operator=(const MutantStack& copy) {
    if (this != &copy) {
      std::stack<T>::operator=(copy);
    }
    return *this;
  }

  /**
   * @brief Destructor.
   *
   * add `virtual` to destruct derived class object
   */
  virtual ~MutantStack() {}

  /**
   * @brief Type definition for the iterator.
   */
  typedef typename std::stack<T>::container_type::iterator iterator;

  /**
   * @brief Returns an iterator to the beginning of the stack.
   *
   * @return iterator An iterator pointing to the beginning of the stack.
   */
  iterator begin() { return this->c.begin(); }

  /**
   * @brief Returns an iterator to the end of the stack.
   *
   * @return iterator An iterator pointing to the end of the stack.
   */
  iterator end() { return this->c.end(); }
};
