#include "ScavTrap.hpp"

int main() {
  {
    ScavTrap a("TEST_A");

    std::cout << std::endl;
    a.guardGate();
    std::cout << std::endl;

    a.attack("world");
    std::cout << "HP is: " << a.getHP() << std::endl;
    a.takeDamage(1);
    std::cout << "HP is: " << a.getHP() << std::endl;
    a.beRepaired(1);
    std::cout << "HP is: " << a.getHP() << std::endl;

    a.takeDamage(100);
    std::cout << "HP is: " << a.getHP() << std::endl;
    a.beRepaired(100);
    std::cout << "HP is: " << a.getHP() << std::endl;
    a.takeDamage(100);
    std::cout << "HP is: " << a.getHP() << std::endl;
  }
}
