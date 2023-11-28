#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
  Zombie *zombie;

  try {
    zombie = new Zombie[N];
    for (int i = 0; i < N; i++) {
      zombie[i]._setZombie(name);
    }
  } catch (const std::bad_alloc &e) {
    std::cout << "Allocation failed: " << e.what() << std::endl;
    return (NULL);
  }
  return (zombie);
}
