#ifndef EASYFIND_H
#define EASYFIND_H

#include <iterator>
#include <stdexcept>

template <typename T> class Maybe {
  enum { NOTHING, JUST } state;
  union {
    char data[sizeof(T)];
    long align1;
    double align2;
    long double align3;
    void *align4;
  } val;

  T *ptr() { return reinterpret_cast<T *>(val.data); }
  const T *ptr() const { return reinterpret_cast<const T *>(val.data); }

  Maybe() : state(NOTHING) {};
  Maybe(const T &val) : state(JUST) { new (ptr()) T(val); }

public:
  static Maybe Nothing() { return Maybe(); }
  static Maybe Just(const T &val) { return Maybe(val); }

  Maybe(const Maybe &other) : state(other.state) {
    if (state == JUST) {
      new (ptr()) T(*other.ptr());
    }
  }
  ~Maybe() {
    if (state == JUST) {
      ptr()->~T();
    }
  }
  Maybe &operator=(Maybe const &other) {
    if (this != &other) {
      if (state == JUST) {
        ptr()->~T();
      }
      state = other.state;
      if (state == JUST) {
        new (ptr()) T(*other.ptr());
      }
    }
    return *this;
  }

  T &operator*() {
    if (state == NOTHING)
      throw std::domain_error("there is nothing to get!");
    return *ptr();
  }

  T const &operator*() const {
    if (state == NOTHING)
      throw std::domain_error("there is nothing to get!");
    return *ptr();
  }
};

template <typename C>
Maybe<typename C::value_type> easyfind(C &cont, int const &val) {
  for (typename C::iterator iter = cont.begin(); iter != cont.end(); ++iter) {
    typename std::iterator_traits<typename C::iterator>::reference ref = *iter;
    if (val == ref)
      return Maybe<typename C::value_type>::Just(ref);
  }
  return Maybe<typename C::value_type>::Nothing();
}

#endif
