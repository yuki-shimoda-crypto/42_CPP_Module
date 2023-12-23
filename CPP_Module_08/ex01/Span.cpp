#include "Span.hpp"

Span::Span() : _maxLen(0) {}

Span::Span(unsigned int n) : _maxLen(n) {}

Span::Span(const Span &span) : _maxLen(span._maxLen), _nums(span._nums) {}

Span::~Span(){};

void Span::addNumber(int num) {
  if (this->_nums.size() >= _maxLen) {
    throw std::length_error("Span is already full");
  }
  this->_nums.push_back(num);
};

unsigned int Span::shortestSpan() const {
  unsigned int shortest = std::numeric_limits<unsigned int>::max();

  if (this->_nums.size() < 2) {
    throw std::logic_error("There are no numbers stored, or only one");
  }
  std::vector<int> tmp(this->_nums);
  std::sort(tmp.begin(), tmp.end());
  for (std::size_t i = 0; i < tmp.size() - 1; i++) {
    if (static_cast<unsigned int>(tmp[i + 1] - tmp[i]) < shortest) {
      shortest = tmp[i + 1] - tmp[i];
    }
  }
  return (shortest);
}

unsigned int Span::longestSpan() const {
  if (this->_nums.size() < 2) {
    throw std::logic_error("There are no numbers stored, or only one");
  }

  std::vector<int> tmp(this->_nums);
  std::sort(tmp.begin(), tmp.end());
  return (static_cast<unsigned int>(tmp.back() - tmp.front()));
}
