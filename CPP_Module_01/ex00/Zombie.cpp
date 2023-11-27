#include "Zombie.hpp"

Zombie::Zombie(void) { this->_name = "foo"; }

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(void) { this->announce(); }

void Zombie::announce(void) const {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
