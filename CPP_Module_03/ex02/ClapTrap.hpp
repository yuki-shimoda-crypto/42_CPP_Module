#ifndef CLAPTRAP_CPP
#define CLAPTRAP_CPP

#include <iostream>
#include <string>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &claptrap);
  ClapTrap &operator=(const ClapTrap &claptrap);
  virtual ~ClapTrap();
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  int getHP(void) const;

protected:
  std::string _name;
  int _hitPoint;
  int _energyPoint;
  int _attackDamage;
};

#endif
