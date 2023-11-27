#include "Zombie.hpp"

int main(void) {
  {
    Zombie zombie;
    zombie.announce();
  }
  {
    Zombie *new_zombie = Zombie::newZombie("newZombie");
    new_zombie->announce();
    delete new_zombie;
  }
  { Zombie::randomChump("randomChump"); }
  return (0);
}
