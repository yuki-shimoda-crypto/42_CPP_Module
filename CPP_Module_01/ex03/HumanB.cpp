#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::attack(void) const {
  if (_weapon == NULL) {
  	std::cout << this->_name << " dose not have a weapon." << std::endl;
  }
  else {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType()
              << std::endl;
  }
}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
