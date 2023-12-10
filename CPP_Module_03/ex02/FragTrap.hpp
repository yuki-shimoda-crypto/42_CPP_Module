#ifndef FRAGTRAP_CPP
#define FRAGTRAP_CPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &scavtrap);
  FragTrap &operator=(const FragTrap &scavtrap);
  ~FragTrap();
  void attack(const std::string &target);
  void guardGate();
  void highFivesGuys(void);

private:
};

#endif
