#include "easyfind.h"
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  const int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
  std::vector<int> is(arr, arr + (sizeof(arr) / sizeof(arr[0])));

  Maybe<int> val1 = easyfind(is, 9);
  try {
    std::cout << *val1 << std::endl;
  } catch (std::domain_error &e) {
    std::cerr << e.what() << std::endl;
  }
  Maybe<int> val2 = easyfind(is, 10);
  try {
    std::cout << *val2 << std::endl;
  } catch (std::domain_error &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
