#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog: Default constructor called" << std::endl;
  this->_brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog) {
  std::cout << "Dog: Copy constructor called" << std::endl;
  if (dog._brain) {
    this->_brain = new Brain(*(dog._brain));
  } else {
    this->_brain = NULL;
  }
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Dog: Copy assign operator called" << std::endl;
  if (this != &dog) {
    Animal::operator=(dog);
    delete this->_brain;
    this->_brain = new Brain(*(dog._brain));
  }
  return (*this);
}

Dog::~Dog() {
  delete this->_brain;
  std::cout << "Dog: Default destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "гав-гав" << std::endl; }
