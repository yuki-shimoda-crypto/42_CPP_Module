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
  static Zombie *newZombie(std::string name);
  static void randomChump(std::string name);

private:
  std::string _name;
};

#endif
