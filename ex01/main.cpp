#include "Span.h"
#include <iostream>
#include <vector>

int main() {
  const int is[5] = {6, 3, 17, 9, 11};
  std::vector<int> vec(is, is + sizeof(is) / sizeof(is[0]));
  Span sp = Span(5);
  sp.addNumbers(vec.begin(), vec.end());
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  return 0;
}
