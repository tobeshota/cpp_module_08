#include <list>

#include "MutantStack.hpp"

static void MutantStackTestExample() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << " ";  //  {17, 5} in mstack
  mstack.pop();
  std::cout << mstack.size() << " ";  //  {5} in mstack
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it =
      mstack.begin();  // {0, 737, 5, 3, 5} in mstack
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
}

static void StdListTestExample() {
  // distinguish between "list"(commonly used) and "llist"(std::list container)
  std::list<int> llist;

  llist.push_back(5);
  llist.push_back(17);
  std::cout << llist.back() << " ";  //  {17, 5} in mlist
  llist.pop_back();
  std::cout << llist.size() << " ";  //  {5} in mlist
  llist.push_back(3);
  llist.push_back(5);
  llist.push_back(737);
  llist.push_back(0);
  std::list<int>::iterator it = llist.begin();  // {0, 737, 5, 3, 5} in mlist
  std::list<int>::iterator ite = llist.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
}

/**
 * @brief The entry point of the program.
 *
 * This function demonstrates the usage of the MutantStack class,
 * which extends the standard stack to provide iterable functionality.
 *
 * The MutantStack allows users to push, pop, and access elements,
 * as well as iterate through its contents using iterators. The goal
 * of this assignment is to implement a stack that supports all
 * member functions of std::stack, while also adding the ability
 * to traverse the elements, thus addressing the limitation of
 * std::stack being non-iterable.
 *
 * @return int The exit status of the program.
 */
int main(void) {
  std::cout << "- MutantStack - - - - - - - - - -" << std::endl;
  MutantStackTestExample();  // expect: 17 1 5 3 5 737 0
  std::cout << "- std::list - - - - - - - - - - -" << std::endl;
  StdListTestExample();  // expect: 17 1 5 3 5 737 0
}
