#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <class T>
void iter(T *array, size_t length, void (*func)(T &element)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

template <class T>
void iter(T *array, size_t length, void (*func)(const T &element)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

// This pattern is not possible
// template <class T>
// void iter(const T *array, size_t length, void (*func)(T &element)) {
//   for (size_t i = 0; i < length; i++) {
//     func(array[i]);
//   }
// }

// template <class T>
// void iter(const T *array, size_t length, void (*func)(const T &element)) {
//   for (size_t i = 0; i < length; i++) {
//     func(array[i]);
//   }
// }

#endif
