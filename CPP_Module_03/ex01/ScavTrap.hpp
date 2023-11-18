#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(ScavTrap scavtrap);
  ScavTrap &operator(const ScavTrap &scavtrap);
  ~ScavTrap();
  void guardGate();

private:

};

ScavTrap::ScavTrap() {
  this->_name = "unknown";
  this->_hit_point = 100;
  this->_energy_point = 50;
  this->_attack_damage = 20;
};
