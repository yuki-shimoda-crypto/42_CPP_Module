#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &wrong_cat);
  WrongCat &operator=(const WrongCat &wrong_cat);
  ~WrongCat();
  void makeSound() const;

private:
};

#endif
