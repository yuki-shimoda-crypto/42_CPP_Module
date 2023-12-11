#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal) {
  std::cout << "WrongAnimal: Copy constructor called" << std::endl;
  *this = wrong_animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrong_animal) {
  std::cout << "WrongAnimal: Copy assign operator called" << std::endl;
  if (this != &wrong_animal) {
    this->_type = wrong_animal._type;
  }
  return (*this);
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal: Default destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal: makeSound" << std::endl;
}

std::string WrongAnimal::getType() const { return (this->_type); }
