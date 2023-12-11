#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
  std::cout << "Cat: Copy constructor called" << std::endl;
  *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
  std::cout << "Cat: Copy assign operator called" << std::endl;
  if (this != &cat) {
    this->_type = cat._type;
  }
  return (*this);
}

Cat::~Cat() { std::cout << "Cat: Default destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "мяу" << std::endl; }
