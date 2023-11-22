#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &animal);
  Animal &operator=(const Animal &animal);
  virtual ~Animal();
  virtual void makeSound() const;
  std::string getType() const;

protected:
  std::string _type;
};

#endif
