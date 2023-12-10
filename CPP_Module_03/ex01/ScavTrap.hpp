#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &scavtrap);
  ScavTrap &operator=(const ScavTrap &scavtrap);
  ~ScavTrap();
  void attack(const std::string &target);
  void guardGate();

private:
};

#endif
