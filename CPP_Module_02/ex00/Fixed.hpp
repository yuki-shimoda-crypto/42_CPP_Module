#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _fixed_point;
  static const int _bits = 8;
};

#endif
