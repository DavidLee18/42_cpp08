#ifndef SPAN_H
#define SPAN_H

#include <cstddef>
#include <stdexcept>

class Span {
  int *ptr;
  size_t len;
  size_t cap;

public:
  Span();
  Span(unsigned int);
  Span(Span const &);
  ~Span();

  Span &operator=(Span const &);
  void addNumber(int) throw(std::domain_error);
  size_t shortestSpan() const throw(std::domain_error);
  size_t longestSpan() const throw(std::domain_error);
  template <typename T>
  void addNumbers(T iter_begin, T iter_end) throw(std::domain_error) {
    for (T it = iter_begin; it != iter_end; it++) {
      if (len == cap)
        throw std::domain_error("Span is full!");
      ptr[len++] = *it;
    }
  }
};

#endif
