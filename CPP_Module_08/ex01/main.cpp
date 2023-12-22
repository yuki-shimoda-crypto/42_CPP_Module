#include "Span.hpp"

int main() {
  {
    Span span(10);

    try {
      span.addNumber(0);
      span.addNumber(6);
      span.addNumber(4);
      span.addNumber(0);
      span.addNumber(0);
      span.addNumber(0);
      span.addNumber(0);
      span.addNumber(0);
      span.addNumber(0);
      span.addNumber(0);
      span.addNumber(0);
      std::cout << span.shortestSpan() << std::endl;
      std::cout << span.longestSpan() << std::endl;
    } catch (const std::length_error &e) {
      std::cout << e.what() << std::endl;
    } catch (const std::logic_error &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    Span sp = Span(100000);
    std::vector<int> range(10000);

    std::iota(range.begin(), range.end(), 0);
    sp.addNumbers(range.begin(), range.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  return (0);
}
