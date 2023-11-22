#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat: Default constructor called" << std::endl;
  this->_brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat) {
  std::cout << "Cat: Copy constructor called" << std::endl;
  if (cat._brain) {
    this->_brain = new Brain(*(cat._brain));
  } else {
    this->_brain = NULL;
  }
}

Cat &Cat::operator=(const Cat &cat) {
  std::cout << "Cat: Copy assign operator called" << std::endl;
  if (this != &cat) {
    Animal::operator=(cat);
    this->_type = cat._type;
    delete this->_brain;
    this->_brain = new Brain(*(cat._brain));
  }
  return (*this);
}

Cat::~Cat() {
  delete this->_brain;
  std::cout << "Cat: Default destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "мяу" << std::endl; }
