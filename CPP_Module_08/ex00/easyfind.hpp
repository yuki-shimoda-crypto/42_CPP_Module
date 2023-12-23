#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class NotFoundException : public std::exception {
public:
  const char *what() const throw() {
    return "Element not found in the container";
  }
};

template <class T>
typename T::iterator easyfind(T &container, int value) {
  typename T::iterator result =
      std::find(std::begin(container), std::end(container), value);
  if (result == std::end(container)) {
    throw NotFoundException();
  }
  return (result);
}

#endif
