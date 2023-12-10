#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("unknown"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
  std::cout << "ClapTrap parameterized constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
  std::cout << "ClapTrap copy assign operator called" << std::endl;
  if (this != &claptrap) {
    this->_name = claptrap._name;
    this->_hitPoint = claptrap._hitPoint;
    this->_energyPoint = claptrap._energyPoint;
    this->_attackDamage = claptrap._attackDamage;
  }
  return (*this);
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_energyPoint -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks," << target
              << " causing " << this->_hitPoint << " points of damage!"
              << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "ClapTrap " << this->_name
              << " is already knocked out and can't attack!" << std::endl;
  } else {
    std::cout << "ClapTrap " << this->_name << " has no energy left to attack!"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (0 < this->_hitPoint) {
    this->_hitPoint -= amount;
    std::cout << "ClapTrap " << this->_name << " takes damages,"
              << " causing " << amount << " points of damage!" << std::endl;
  } else {
    std::cout << "ClapTrap " << this->_name << " has already been knocked out!"
              << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (0 < this->_energyPoint && 0 < this->_hitPoint) {
    this->_hitPoint += amount;
    this->_energyPoint -= 1;
    std::cout << "ClapTrap " << this->_name << " is repaired,"
              << " causing " << amount << " points of repaire!" << std::endl;
  } else if (this->_hitPoint <= 0) {
    std::cout << "ClapTrap " << this->_name
              << " can't be repaired anymore, it's too late!" << std::endl;
  } else {
    std::cout << "ClapTrap " << this->_name
              << " has no energy left to repair itself!" << std::endl;
  }
}

int ClapTrap::getHP(void) { return (this->_hitPoint); }
