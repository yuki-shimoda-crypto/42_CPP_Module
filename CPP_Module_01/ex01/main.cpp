#include "Zombie.hpp"

int main(void) {
  int n = 2;
  Zombie *zombies;

  zombies = Zombie::zombieHorde(n, "name");
  if (zombies == NULL) {
    std::cerr << "Failed to create zombie horde." << std::endl;
    return (1);
  }
  for (int i = 0; i < n; i++) {
    zombies[i].announce();
  }
  delete[] zombies;
  return (0);
}
