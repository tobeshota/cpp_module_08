#include <iostream>
#include <stdexcept>
#include <vector>

#include "easyfind.hpp"

int main() {
  // 検索対象となるコンテナを用意
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  try {
    // 値3を検索
    std::cout << "Searching for 3:\t\t" << *easyfind(vec, 3) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    // 値4をconst参照のコンテナで検索
    const std::vector<int> &cvec = vec;
    std::cout << "Searching for const 4:\t\t" << *easyfind(cvec, 4) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    // 存在しない値6を検索
    std::cout << "Searching for 6:\t\t" << *easyfind(vec, 6) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    // 空のコンテナを検索
    std::vector<int> emptyVec;
    std::cout << "Searching in an empty vector:\t" << *easyfind(emptyVec, 1)
              << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
