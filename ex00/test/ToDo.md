# ToDo List for Exercise 00: Easy find

- [ ] **Test ValueFound**
    - [ ] Verify that the `easyfind` function correctly finds values present in the container and returns the appropriate iterator.
    - [ ] Test cases:
        - Check if `easyfind(vec, 3)` returns an iterator pointing to the value 3.
        - Check if `easyfind(vec, 1)` returns an iterator pointing to the value 1.
        - Check if `easyfind(vec, 5)` returns an iterator pointing to the value 5.

- [ ] **Test ValueNotFound**
    - [ ] Verify that the `easyfind` function throws a `std::invalid_argument` exception when the value is not found in the container.
    - [ ] Test cases:
        - Check if `easyfind(vec, 6)` throws an exception.
        - Check if `easyfind(vec, 0)` throws an exception.

- [ ] **Test EmptyContainer**
    - [ ] Verify that the `easyfind` function throws a `std::invalid_argument` exception when called on an empty container.
    - [ ] Test cases:
        - Check if `easyfind(emptyVec, 1)` throws an exception for an empty container.
