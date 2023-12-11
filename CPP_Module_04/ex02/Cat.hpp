#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &cat);
  Cat &operator=(const Cat &cat);
  ~Cat();
  void makeSound() const;
  const Brain *getBrain() const;

private:
  Brain *_brain;
};

#endif
