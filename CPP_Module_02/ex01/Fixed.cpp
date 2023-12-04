#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNum(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedPointNum((n << _bits)) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
    : _fixedPointNum(roundFloatToFixed(n * (1 << _bits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) {
    this->_fixedPointNum = fixed.getRawBits();
  }
  return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  //  std::cout << "getRawBits member function called" << std::endl;
  return (this->_fixedPointNum);
}

void Fixed::setRawBits(int const raw) {
  //  std::cout << "setRawBits member function called" << std::endl;
  this->_fixedPointNum = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->getRawBits()) / (1 << _bits));
}

int Fixed::toInt(void) const { return (this->_fixedPointNum >> _bits); }

int Fixed::roundFloatToFixed(float n) const {
  if (n > 0) {
    n += 0.5;
  } else {
    n -= 0.5;
  }
  return (static_cast<int>(n));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return (os);
}
