#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);
  void announce(void) const;
  static Zombie *zombieHorde(int N, std::string name);

private:
  std::string _name;
  void _setZombie(std::string name);
};

#endif
