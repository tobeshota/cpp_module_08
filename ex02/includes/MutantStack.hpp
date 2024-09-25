#pragma once
#include <iostream>
#include <stack>

/**
 * @class MutantStack
 * @brief A stack that allows iteration over its elements, unlike the standard
 * std::stack.
 *
 * MutantStack extends std::stack by providing iterators, making it possible to
 * iterate over the elements contained in the stack. This class inherits from
 * std::stack but exposes iterator functionality that is typically encapsulated
 * by the underlying container in the std::stack.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class MutantStack : public std::stack<T> {
 public:
  /**
   * @brief Default constructor for MutantStack.
   *
   * Constructs an empty MutantStack object. This constructor does not allocate
   * any resources or perform any specific initialization apart from creating
   * an empty stack.
   */
  MutantStack() : std::stack<T>() {}

  /**
   * @brief Copy constructor.
   *
   * Initializes a new MutantStack as a copy of an existing one.
   *
   * @param copy The MutantStack object to copy from.
   */
  MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

  /**
   * @brief Copy assignment operator.
   *
   * Assigns one MutantStack object to another, copying its elements.
   *
   * @param copy The MutantStack object to copy from.
   * @return MutantStack& A reference to the newly assigned stack.
   */
  MutantStack& operator=(const MutantStack& copy) {
    if (this != &copy) {
      std::stack<T>::operator=(copy);
    }
    return *this;
  }

  /**
   * @brief Virtual destructor.
   *
   * Ensures that any derived class objects are properly cleaned up during
   * destruction. This is especially important when polymorphism is involved.
   */
  virtual ~MutantStack() {}

  /**
   * @typedef iterator
   * @brief Type alias for a mutable iterator.
   *
   * Allows for iterating through elements of the stack in a non-const manner.
   */
  typedef typename std::stack<T>::container_type::iterator iterator;

  /**
   * @typedef const_iterator
   * @brief Type alias for a const iterator.
   *
   * Allows for iterating through elements of the stack without modifying them.
   */
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  /**
   * @typedef reverse_iterator
   * @brief Type alias for a mutable reverse iterator.
   *
   * Allows for reverse iteration over elements of the stack.
   */
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

  /**
   * @typedef const_reverse_iterator
   * @brief Type alias for a const reverse iterator.
   *
   * Allows for reverse iteration over elements of the stack without modifying
   * them.
   */
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  /**
   * @brief Returns a mutable iterator to the beginning of the stack.
   *
   * @return iterator An iterator pointing to the first element in the stack.
   */
  iterator begin() { return this->c.begin(); }

  /**
   * @brief Returns a const iterator to the beginning of the stack.
   *
   * @return const_iterator A const iterator pointing to the first element in
   * the stack.
   */
  const_iterator begin() const { return this->c.begin(); }

  /**
   * @brief Returns a mutable iterator to the end of the stack.
   *
   * The end iterator points one past the last element in the stack.
   *
   * @return iterator An iterator pointing one past the last element in the
   * stack.
   */
  iterator end() { return this->c.end(); }

  /**
   * @brief Returns a const iterator to the end of the stack.
   *
   * The end iterator points one past the last element in the stack.
   *
   * @return const_iterator A const iterator pointing one past the last element
   * in the stack.
   */
  const_iterator end() const { return this->c.end(); }

  /**
   * @brief Returns a mutable reverse iterator to the beginning of the reversed
   * stack.
   *
   * This allows reverse traversal of the stack, starting from the last element.
   *
   * @return reverse_iterator A reverse iterator pointing to the last element of
   * the stack.
   */
  reverse_iterator rbegin() { return this->c.rbegin(); }

  /**
   * @brief Returns a const reverse iterator to the beginning of the reversed
   * stack.
   *
   * This allows reverse traversal of the stack without modifying the elements.
   *
   * @return const_reverse_iterator A const reverse iterator pointing to the
   * last element of the stack.
   */
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }

  /**
   * @brief Returns a mutable reverse iterator to the end of the reversed stack.
   *
   * The reverse end iterator points to one before the first element in the
   * stack.
   *
   * @return reverse_iterator A reverse iterator pointing one before the first
   * element of the stack.
   */
  reverse_iterator rend() { return this->c.rend(); }

  /**
   * @brief Returns a const reverse iterator to the end of the reversed stack.
   *
   * The reverse end iterator points to one before the first element in the
   * stack.
   *
   * @return const_reverse_iterator A const reverse iterator pointing one before
   * the first element of the stack.
   */
  const_reverse_iterator rend() const { return this->c.rend(); }
};
