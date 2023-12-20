#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <class T> void swap(T &a, T &b) {
  T tmp;

  tmp = a;
  a = b;
  b = tmp;
}

template <class T> const T &min(const T &a, const T &b) {
  if (a < b) {
    return (a);
  } else {
    return (b);
  }
}

template <class T> const T &max(const T &a, const T &b) {
  if (a > b) {
    return (a);
  } else {
    return (b);
  }
}

#endif
