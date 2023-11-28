#include "Zombie.hpp"

int main(void) {
  int n = 2;
  Zombie *zombies;

  zombies = Zombie::zombieHorde(n, "name");
  for (int i = 0; i < n; i++) {
    zombies[i].announce();
  }
  delete[] zombies;
  return (0);
}
