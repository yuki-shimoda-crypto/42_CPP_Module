#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <vector>

class Span {
public:
  Span();
  Span(unsigned int n);
  Span(const Span &span);
  ~Span();
  void addNumber(int num);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  template <class InputIt> void addNumbers(InputIt first, InputIt last);

private:
  unsigned int _maxLen;
  std::vector<int> _nums;
};

template <class InputIt> void Span::addNumbers(InputIt first, InputIt last) {
  if (std::distance(first, last) + this->_nums.size() > this->_maxLen) {
    throw std::length_error(
        "Adding these numbers would exceed Span's capacity");
  }
  this->_nums.insert(this->_nums.end(), first, last);
}

#endif
