# CPP MODULE 08 - Templated Containers, Iterators, Algorithms

## Table of Contents
- [Overview](#overview)
- [Learning Outcomes](#learning-outcomes)
- [Concepts Covered](#concepts-covered)
  - [Containers](#containers)
  - [Iterators](#iterators)
  - [Templated Functions](#templated-functions)
- [Tests](#tests)
- [Documentation](#documentation)

## Overview
The exercises in this repository are designed to help learners develop a deeper understanding of the C++ Standard Library's containers, iterators, and algorithms. Additionally, it introduces the principles of template programming and how to use these techniques to solve real-world problems. The tasks also focus on adhering to C++98 standards, which ensures a foundational understanding of the language before moving on to more modern features.

## Learning Outcomes
Through these exercises, you will:
- Gain experience with **STL containers** and learn how to efficiently store and manipulate data using vectors, stacks, and other containers.
- Understand the role of **iterators** in traversing and accessing elements in containers.
- Develop proficiency in **template programming**, allowing you to write reusable code that can operate on different data types.
- Practice writing **robust and exception-safe code**, with a focus on proper error handling and resource management.
- Build a foundation in C++98 standards, focusing on object-oriented design and memory management without relying on newer C++ features.

## Concepts Covered

### Containers
C++ containers are essential data structures used to store collections of objects. In these exercises, we focus on:
- **`std::vector`** for dynamic arrays.
- **`std::stack`**, a container adapter implementing a LIFO (Last In, First Out) structure.

### Iterators
Iterators allow traversal of elements within containers. You will learn how to utilize iterators to access, modify, and search elements efficiently.

### Templated Functions
C++ templates provide a way to write generic functions and classes that can operate on various data types. You will develop templated functions that can work with different container types.

## Tests
Unit tests are written using the [**GoogleTest**](https://google.github.io/googletest/) framework to ensure the correctness of the implemented functions and classes. These tests cover both normal cases and edge cases, such as:
- Finding values that exist and do not exist in a container.
- Handling empty containers and triggering exceptions.

To run the tests:
```bash
make test
```

If you add tests, please follow the rules below.
- File extension must be `.cpp` or `.hpp`.
- The name of the file where the main function is defined must be `main.cpp`.
- Test files must be placed under `exXX/test/srcs/`.

## Documentation
This project includes Doxygen-style comments for automatic documentation generation. To generate the documentation, run:
```bash
make doc
```
