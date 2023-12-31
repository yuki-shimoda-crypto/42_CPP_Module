#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &animal);
  Animal &operator=(const Animal &animal);
  virtual ~Animal();
  virtual void makeSound() const = 0;
  std::string getType() const;

protected:
  std::string _type;
};

#endif
