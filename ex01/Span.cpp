#include "Span.h"
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>

Span::Span() : ptr(NULL), len(0), cap(0) {}

Span::Span(unsigned int l) : ptr(new int[l]), len(0), cap(l) {
  for (size_t i = 0; i < cap; i++) {
    ptr[i] = 0;
  }
}

Span::Span(Span const &other)
    : ptr(new int[other.cap]), len(other.len), cap(other.cap) {
  for (size_t i = 0; i < cap; i++) {
    if (i < len)
      ptr[i] = other.ptr[i];
    else
      ptr[i] = 0;
  }
}

Span::~Span() {
  if (ptr) {
    delete[] ptr;
  }
}

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    if (ptr)
      delete[] ptr;
    ptr = new int[other.cap];
    len = other.len;
    cap = other.cap;
    for (size_t i = 0; i < cap; i++) {
      if (i < len)
        ptr[i] = other.ptr[i];
      else
        ptr[i] = 0;
    }
  }
  return *this;
}

void Span::addNumber(int i) throw(std::domain_error) {
  if (len == cap)
    throw std::domain_error("Span is full!");
  ptr[len++] = i;
}

size_t Span::longestSpan() const throw(std::domain_error) {
  if (len <= 1)
    throw std::domain_error("there could be no Span!");
  int min = ptr[0], max = ptr[0];
  for (size_t i = 1; i < len; i++) {
    if (ptr[i] < min)
      min = ptr[i];
    else if (ptr[i] > max)
      max = ptr[i];
  }
  return static_cast<size_t>(max - min);
}

size_t Span::shortestSpan() const throw(std::domain_error) {
  if (len <= 1)
    throw std::domain_error("there could be no Span!");
  int res = INT_MAX;
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j < len; j++) {
      if (i != j && std::abs(ptr[i] - ptr[j]) < res)
        res = std::abs(ptr[i] - ptr[j]);
    }
  }
  return static_cast<size_t>(res);
}
