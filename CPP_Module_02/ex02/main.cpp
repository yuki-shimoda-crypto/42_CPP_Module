#include "Fixed.hpp"
#include <cassert>

int main(void) {
  // default test case
  {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << std::endl;
  }

  // test >, <, >=, <=, ==, !=
  {
    Fixed a(0);
    Fixed b(1);
    Fixed c(a);

    assert(b > a);
    std::cout << "b > a: OK" << std::endl;
    assert(a < b);
    std::cout << "a < b: OK" << std::endl;

    assert(b >= a);
    std::cout << "b >= a: OK" << std::endl;
    assert(c >= a);
    std::cout << "c >= a: OK" << std::endl;
    assert(a <= b);
    std::cout << "a <= b: OK" << std::endl;
    assert(a <= c);
    std::cout << "a <= c: OK" << std::endl;

    assert(a == c);
    std::cout << "a == c: OK" << std::endl;
    assert(a != b);
    std::cout << "a != c: OK" << std::endl;

    std::cout << std::endl;
  }

  // test +, -, *, /
  {
    Fixed a(1);
    Fixed b(2);

    std::cout << "Fixed a(1) + Fixed b(2): " << a + b << std::endl;
    std::cout << "Fixed a(1) - Fixed b(2): " << a - b << std::endl;
    std::cout << "Fixed a(1) * Fixed b(2): " << a * b << std::endl;
    std::cout << "Fixed a(1) / Fixed b(2): " << a / b << std::endl;
    std::cout << std::endl;
  }

  // test increment, decrement
  {
    Fixed a(0);

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "  a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "  a: " << a << std::endl;
    std::cout << std::endl;
  }

  // test max, min
  {
    Fixed a(0);
    Fixed b(1);

    std::cout << "min: " << Fixed::min(a, b) << std::endl;
    std::cout << "max: " << Fixed::max(a, b) << std::endl;
    std::cout << std::endl;
  }

  return (0);
}
