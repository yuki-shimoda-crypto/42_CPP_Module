#include "Zombie.hpp"

int main(void) {
  {
    Zombie zombie;
    zombie.announce();
  }
  {
    Zombie *new_zombie = Zombie::newZombie("newZombie");
    if (new_zombie == NULL) {
      std::cerr << "Failed to create new zombie." << std::endl;
      return (1);
    }
    new_zombie->announce();
    delete new_zombie;
  }
  { Zombie::randomChump("randomChump"); }
  return (0);
}
