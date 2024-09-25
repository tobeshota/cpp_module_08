# ToDo List for Exercise 01: Span

Here, you will create a `Span` class that can store a specified number of integers and calculate the shortest and longest spans between them. Exceptions should be thrown in cases where spans cannot be calculated or when capacity is exceeded.

## Files:
- `Span.hpp` - Declaration of the `Span` class.
- `Span.cpp` - Implementation of the `Span` class.
- `main.cpp` - Demonstrates usage of `Span`.

## Tests:

### 1. **AddNumber Test**
   - **Description**: Verify the functionality of the `addNumber` method.
   - **Test**:
     - Create a `Span` instance with a capacity of 5.
     - Add five numbers to the span.
     - Attempt to add a sixth number and check that an `AlreadyFilledException` is thrown.

### 2. **ShortestSpan Test**
   - **Description**: Verify the functionality of the `shortestSpan` method.
   - **Test**:
     - Create a `Span` instance with a capacity of 5.
     - Add numbers: 1, 5, 10, 20, and 25.
     - Check that the calculated shortest span equals 4 (5 - 1).

### 3. **LongestSpan Test**
   - **Description**: Verify the functionality of the `longestSpan` method.
   - **Test**:
     - Create a `Span` instance with a capacity of 5.
     - Add numbers: 1, 5, 10, 20, and 25.
     - Check that the calculated longest span equals 24 (25 - 1).

### 4. **Empty Exception Test**
   - **Description**: Ensure an exception is thrown when calculating spans on an empty span.
   - **Test**:
     - Create a `Span` instance with a capacity of 5.
     - Attempt to call `shortestSpan` and `longestSpan` without adding any numbers.
     - Confirm that an `EmptyException` is thrown.

### 5. **Only One Number Stored Exception Test**
   - **Description**: Ensure an exception is thrown when calculating spans with only one number.
   - **Test**:
     - Create a `Span` instance with a capacity of 5.
     - Add one number (1).
     - Confirm that calling `shortestSpan` and `longestSpan` throws an `OnlyOneNumberStoredException`.

### 6. **FillSpan Test**
   - **Description**: Verify the functionality of the `fillSpan` method.
   - **Test**:
     - Create a `Span` instance with a capacity of 10,000.
     - Call `fillSpan` to populate it with random integers.
     - Ensure that both `shortestSpan` and `longestSpan` can be calculated without throwing exceptions.

### 7. **Copy Constructor and Assignment Test**
   - **Description**: Verify the functionality of the copy constructor and assignment operator.
   - **Test**:
     - Create a `Span` instance and add numbers.
     - Use the copy constructor to create a new `Span` and check that it retains the same state.
     - Create another `Span`, assign it from the original, and ensure it also retains the same state.

