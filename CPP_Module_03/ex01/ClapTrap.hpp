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
  ~ClapTrap();
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  int getHP(void);

private:
  std::string _name;
  int _hit_point;
  int _energy_point;
  int _attack_damage;
};

#endif
