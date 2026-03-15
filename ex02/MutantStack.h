#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <cstddef>
#include <deque>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
public:
  typedef typename C::iterator iterator;
  MutantStack() { this->c = C(); }
  MutantStack(MutantStack const &other) { this->c = C(other.c); }
  ~MutantStack() {}

  MutantStack &operator=(MutantStack const &other) {
    if (this != &other) {
      this->c = other.c;
    }
  }
  T &top() { return this->c.back(); }
  T const &top() const { return this->c.back(); }
  bool empty() { return this->c.empty(); }
  std::size_t size() { return this->c.size(); }
  void push(const T &value) { this->c.push_back(value); }
  void pop() { this->c.pop_back(); }
  typename C::iterator begin() { return this->c.begin(); }
  typename C::iterator end() { return this->c.end(); }
};

#endif
