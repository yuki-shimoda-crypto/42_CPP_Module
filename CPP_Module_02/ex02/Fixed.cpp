#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNum(0) {}

Fixed::Fixed(const int n) : _fixedPointNum((n << _bits)) {}

Fixed::Fixed(const float n)
    : _fixedPointNum(roundFloatToFixed(n * (1 << _bits))) {}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed &Fixed::operator=(const Fixed &fixed) {
  if (this != &fixed) {
    this->_fixedPointNum = fixed.getRawBits();
  }
  return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return (this->_fixedPointNum); }

void Fixed::setRawBits(int const raw) { this->_fixedPointNum = raw; }

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->getRawBits()) / (1 << _bits));
}
int Fixed::toInt(void) const { return (this->_fixedPointNum >> _bits); }

bool Fixed::operator>(const Fixed &fixed) const {
  if (this->_fixedPointNum > fixed._fixedPointNum) {
    return (true);
  } else {
    return (false);
  }
}

bool Fixed::operator<(const Fixed &fixed) const {
  if (this->_fixedPointNum < fixed._fixedPointNum) {
    return (true);
  } else {
    return (false);
  }
}

bool Fixed::operator>=(const Fixed &fixed) const {
  if (this->_fixedPointNum >= fixed._fixedPointNum) {
    return (true);
  } else {
    return (false);
  }
}

bool Fixed::operator<=(const Fixed &fixed) const {
  if (this->_fixedPointNum <= fixed._fixedPointNum) {
    return (true);
  } else {
    return (false);
  }
}

bool Fixed::operator==(const Fixed &fixed) const {
  if (this->_fixedPointNum == fixed._fixedPointNum) {
    return (true);
  } else {
    return (false);
  }
}

bool Fixed::operator!=(const Fixed &fixed) const {
  if (this->_fixedPointNum != fixed._fixedPointNum) {
    return (true);
  } else {
    return (false);
  }
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++() {
  this->_fixedPointNum += 1;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return (tmp);
}

Fixed &Fixed::operator--() {
  this->_fixedPointNum -= 1;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return (tmp);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a > b) {
    return (b);
  }
  return (a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a > b) {
    return (a);
  }
  return (b);
}

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
