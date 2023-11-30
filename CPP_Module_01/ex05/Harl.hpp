#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
public:
  void complain(const std::string &level) const;

private:
  void invalid(void) const;
  void debug(void) const;
  void info(void) const;
  void warning(void) const;
  void error(void) const;
};

#endif
