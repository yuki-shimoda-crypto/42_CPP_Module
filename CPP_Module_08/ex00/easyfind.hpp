#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class NotFoundException : public std::exception {
public:
  const char *what() const throw() {
    return "Element not found in the container";
  }
};

template <class T> T easyfind(T &container, int value) {
  T result = std::find(std::begin(container), std::end(container), value);
  if (result == std::end(container)) {
    throw NotFoundException();
  }
  return (result);
}

#endif
