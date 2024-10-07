/**
 * @file easyfind.hpp
 * @brief write a function template easyfind
 * @author toshota
 * @date 2024/09/23
 * @details ...
 */
#pragma once  //	include guard

#include <algorithm>  //  std::find
#include <vector>     //  because Assuming T is a container of integers: vector

/**
 * @brief Searches for a specific value in the container and returns its
 * iterator if found.
 *
 * @tparam T The container type. The container must support iterators (e.g.,
 * std::vector, std::list).
 * @param vector The container in which to search for the value.
 * @param num The integer value to search for.
 * @return typename T::iterator An iterator pointing to the found value in the
 * container.
 * @throw std::invalid_argument Throws an exception if the specified value is
 * not found in the container.
 *
 * @details This function uses the `std::find` algorithm to search for the
 * integer `num` in the given container `vector`. If the value is not found, an
 * exception is thrown. Otherwise, the iterator pointing to the value is
 * returned.
 *
 * Example usage:
 * @code
 * std::vector<int> vec = {1, 2, 3, 4, 5};
 * try {
 *     auto it = easyfind(vec, 3);  // Returns iterator if found
 *     std::cout << "Found value: " << *it << std::endl;
 * } catch (const std::invalid_argument& e) {
 *     std::cerr << e.what() << std::endl;
 * }
 * @endcode
 */
template <typename T>
typename T::iterator easyfind(T& vector, int num) {
  // template型の値の内部で定義されている型を使用する場合にもtypenameを用いる
  typename T::iterator it = std::find(vector.begin(), vector.end(), num);
  if (it == vector.end()) throw std::invalid_argument("num not found");
  return it;
}

// for const reference container
template <typename T>
typename T::const_iterator easyfind(const T& vector, int num) {
  // template型の値の内部で定義されている型を使用する場合にもtypenameを用いる
  typename T::const_iterator it = std::find(vector.begin(), vector.end(), num);
  if (it == vector.end()) throw std::invalid_argument("num not found");
  return it;
}
