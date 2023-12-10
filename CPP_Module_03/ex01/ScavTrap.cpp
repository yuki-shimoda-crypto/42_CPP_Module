#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  std::cout << "ScavTrap default constructor called" << std::endl;
  this->_name = "unknown";
  this->_hitPoint = 100;
  this->_energyPoint = 50;
  this->_attackDamage = 20;
};

ScavTrap::ScavTrap(std::string name) {
  std::cout << "ScavTrap parameterized constructor called" << std::endl;
  this->_name = name;
  this->_hitPoint = 100;
  this->_energyPoint = 50;
  this->_attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
  std::cout << "ScavTrap copy assign operator called" << std::endl;
  if (this != &scavtrap) {
    this->_name = scavtrap._name;
    this->_hitPoint = scavtrap._hitPoint;
    this->_energyPoint = scavtrap._energyPoint;
    this->_attackDamage = scavtrap._attackDamage;
  }
  return (*this);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap default destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_energyPoint -= 1;
    std::cout << "ScavTrap " << this->_name << " attacks," << target
              << " causing " << this->_hitPoint << " points of damage!"
              << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "ScavTrap " << this->_name
              << " is already knocked out and can't attack!" << std::endl;
  } else {
    std::cout << "ScavTrap " << this->_name << " has no energy left to attack!"
              << std::endl;
  }
}

void ScavTrap::guardGate() {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_energyPoint -= 1;
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "ScavTrap " << this->_name << " has already been knocked out!"
              << std::endl;
  } else {
    std::cout << "ScavTrap " << this->_name << " has no energy." << std::endl;
  }
}
