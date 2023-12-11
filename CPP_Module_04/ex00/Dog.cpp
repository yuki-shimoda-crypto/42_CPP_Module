#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog: Default constructor called" << std::endl;
  this->_type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog) {
  std::cout << "Dog: Copy constructor called" << std::endl;
  *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Dog: Copy assign operator called" << std::endl;
  if (this != &dog) {
    this->_type = dog._type;
  }
  return (*this);
}

Dog::~Dog() { std::cout << "Dog: Default destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "гав-гав" << std::endl; }
