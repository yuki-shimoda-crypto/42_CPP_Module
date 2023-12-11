#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
  std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(const Animal &animal) {
  std::cout << "Animal: Copy constructor called." << std::endl;
  *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
  std::cout << "Animal: Copy assign operator called." << std::endl;
  if (this != &animal) {
    this->_type = animal._type;
  }
  return (*this);
}

Animal::~Animal() {
  std::cout << "Animal: Default destructor called." << std::endl;
}

void Animal::makeSound() const {
  std::cout << "Я не знаю, как я кричу!" << std::endl;
}

std::string Animal::getType() const { return (this->_type); }
