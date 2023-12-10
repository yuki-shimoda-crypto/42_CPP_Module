#include "ClapTrap.hpp"

int main() {
  {
    ClapTrap a;

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
    std::cout << std::endl;
  }
  {
    ClapTrap b("hello");

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
}
