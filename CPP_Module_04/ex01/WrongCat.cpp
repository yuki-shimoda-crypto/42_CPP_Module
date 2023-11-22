#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrong_cat) : WrongAnimal(wrong_cat) {
  std::cout << "WrongCat: Copy constructor called" << std::endl;
  *this = wrong_cat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrong_cat) {
  std::cout << "WrongCat: Copy assign operator called" << std::endl;
  if (this != &wrong_cat) {
    this->_type = wrong_cat._type;
  }
  return (*this);
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat: makeSound" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat: Default destructor called" << std::endl;
}
