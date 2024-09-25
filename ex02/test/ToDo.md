# ToDo List for Exercise 02: Mutated abomination

In this exercise, you will extend the functionality of the `std::stack` container by making it iterable. The goal is to create a `MutantStack` class that behaves like a stack but also supports iteration over its elements.

## Files:
- `MutantStack.hpp` - Declaration and implementation of the `MutantStack` class.
- `main.cpp` - Demonstrates usage of `MutantStack` and compares its behavior to other containers.

## MutantStack-StdListComparisonTest

### 1. **Top Element Comparison Test**
   - **Description**: Verify that the top element of `MutantStack` matches the last element (`back`) of `std::list`.
   - **Test**:
     - Push elements 5 and 17 to both `MutantStack` and `std::list`.
     - Confirm that the top of `MutantStack` equals the back of `std::list`.

### 2. **Size Comparison After Pop Test**
   - **Description**: Ensure that after popping the top element, the size of `MutantStack` matches the size of `std::list`.
   - **Test**:
     - Push elements 5 and 17 to both `MutantStack` and `std::list`.
     - Pop an element from both containers.
     - Check that both sizes are the same.

### 3. **Iterator Comparison Test**
   - **Description**: Verify that `MutantStack`'s iterator behaves like `std::list`'s iterator, traversing elements in the same order.
   - **Test**:
     - Add multiple elements (5, 3, 737, 0) to both `MutantStack` and `std::list`.
     - Iterate through both containers and confirm each element matches.
     - Ensure both iterators reach the end of their containers simultaneously.

## MutantStackTest

### 4. **Push and Pop Test**
   - **Description**: Verify the correct push and pop behavior in `MutantStack`.
   - **Test**:
     - Push elements 5 and 10.
     - Confirm the top element is 10, pop it, and check the new top is 5.
     - Ensure the stack is empty after popping both elements.

### 5. **Size Reporting Test**
   - **Description**: Verify that `MutantStack` reports the correct size after each push and pop.
   - **Test**:
     - Check initial size (0), push elements (1, 2), and verify the size increases accordingly.
     - Pop an element and ensure the size decreases correctly.

### 6. **Iteration Over Elements Test**
   - **Description**: Ensure that `MutantStack` can iterate through its elements.
   - **Test**:
     - Push elements (1, 2, 3) and iterate over them.
     - Confirm each element matches the expected values.

### 7. **Element Order Preservation Test**
   - **Description**: Verify that `MutantStack` maintains the correct LIFO (Last In, First Out) order.
   - **Test**:
     - Push elements (5, 10, 15).
     - Confirm the top element is 15, pop it, and check that the new top is 10, then 5.

### 8. **Copy Constructor Test**
   - **Description**: Verify the copy constructor for `MutantStack`.
   - **Test**:
     - Push elements (1, 2, 3), create a copy, and confirm the copied stack retains the same elements and size.
     - Perform operations on the copied stack and ensure the original stack remains unchanged.
