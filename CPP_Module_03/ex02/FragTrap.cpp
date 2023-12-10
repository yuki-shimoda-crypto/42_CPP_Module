#include "FragTrap.hpp"

FragTrap::FragTrap() {
  std::cout << "FragTrap default constructor called" << std::endl;
  this->_name = "unknown";
  this->_hitPoint = 100;
  this->_energyPoint = 100;
  this->_attackDamage = 30;
};

FragTrap::FragTrap(std::string name) {
  std::cout << "FragTrap parameterized constructor called" << std::endl;
  this->_name = name;
  this->_hitPoint = 100;
  this->_energyPoint = 100;
  this->_attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap &scavtrap) : ClapTrap(scavtrap) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = scavtrap;
}

FragTrap &FragTrap::operator=(const FragTrap &scavtrap) {
  std::cout << "FragTrap copy assign operator called" << std::endl;
  if (this != &scavtrap) {
    this->_name = scavtrap._name;
    this->_hitPoint = scavtrap._hitPoint;
    this->_energyPoint = scavtrap._energyPoint;
    this->_attackDamage = scavtrap._attackDamage;
  }
  return (*this);
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap default destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_energyPoint -= 1;
    std::cout << "FragTrap " << this->_name << " attacks," << target
              << " causing " << this->_hitPoint << " points of damage!"
              << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "FragTrap " << this->_name
              << " is already knocked out and can't attack!" << std::endl;
  } else {
    std::cout << "FragTrap " << this->_name << " has no energy left to attack!"
              << std::endl;
  }
}

void FragTrap::guardGate() {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_energyPoint -= 1;
    std::cout << "FragTrap is now in Gate keeper mode." << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "FragTrap " << this->_name << " has already been knocked out!"
              << std::endl;
  } else {
    std::cout << "FragTrap " << this->_name << " has no energy." << std::endl;
  }
}

void FragTrap::highFivesGuys(void) {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_energyPoint -= 1;
    std::cout << "FragTrap requests a high five !" << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "FragTrap " << this->_name << " has already been knocked out!"
              << std::endl;
  } else {
    std::cout << "FragTrap " << this->_name << " has no energy." << std::endl;
  }
}
