#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
public:
  Fixed();
  Fixed(const int n);
  Fixed(const float n);
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fixedPointNum;
  static const int _bits = 8;
  int roundFloatToFixed(float n) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
