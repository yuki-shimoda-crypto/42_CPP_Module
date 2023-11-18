#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  this->_name = "unknown";
  this->_hit_point = 10;
  this->_energy_point = 10;
  this->_attack_damage = 0;
};

ClapTrap::ClapTrap(std::string name) {
  this->_name = name;
  this->_hit_point = 10;
  this->_energy_point = 10;
  this->_attack_damage = 0;
};

ClapTrap::ClapTrap(const ClapTrap &claptrap) { *this = claptrap; }

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
  if (this != &claptrap) {
    this->_name = claptrap._name;
    this->_hit_point = claptrap._hit_point;
    this->_energy_point = claptrap._energy_point;
    this->_attack_damage = claptrap._attack_damage;
  }
  return (*this);
}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string &target) {
  if (0 < this->_energy_point && 0 < this->_hit_point) {
    this->_energy_point -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << " , causing " << this->_hit_point << " points of damage!"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (0 < this->_hit_point) {
    this->_hit_point -= amount;
    std::cout << "ClapTrap " << this->_name << " takes damages "
              << " , causing " << amount << " points of damage!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (0 < this->_energy_point && 0 < this->_hit_point) {
    this->_hit_point += amount;
    this->_energy_point -= 1;
    std::cout << "ClapTrap " << this->_name << " is repaired "
              << " , causing " << amount << " points of repaire!" << std::endl;
  }
}

int ClapTrap::getHP(void) { return (this->_hit_point); }

int main() {
  ClapTrap a;
  ClapTrap b("hello");

//  a.attack("world");
//  std::cout << "HP is: " << a.getHP() << std::endl;
//  a.takeDamage(1);
//  std::cout << "HP is: " << a.getHP() << std::endl;
//  a.beRepaired(1);
//  std::cout << "HP is: " << a.getHP() << std::endl;
//
//  a.takeDamage(100);
//  std::cout << "HP is: " << a.getHP() << std::endl;
//  a.beRepaired(100);
//  std::cout << "HP is: " << a.getHP() << std::endl;
//  a.takeDamage(100);
//  std::cout << "HP is: " << a.getHP() << std::endl;

  b.attack("world");
  std::cout << "HP is: " << b.getHP() << std::endl;
  b.takeDamage(1);
  std::cout << "HP is: " << b.getHP() << std::endl;
  b.beRepaired(1);
  std::cout << "HP is: " << b.getHP() << std::endl;

  b.takeDamage(100);
  std::cout << "HP is: " << b.getHP() << std::endl;
  b.beRepaired(100);
  std::cout << "HP is: " << b.getHP() << std::endl;
  b.takeDamage(100);
  std::cout << "HP is: " << b.getHP() << std::endl;
}
