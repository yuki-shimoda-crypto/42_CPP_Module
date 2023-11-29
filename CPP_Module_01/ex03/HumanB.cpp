#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {}

void HumanB::attack(void) const {
  std::cout << this->_name << " attacks with their " << this->_weapon->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
