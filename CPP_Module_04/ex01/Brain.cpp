#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain: Default constructor called" << std::endl;
  for (int i = 0; i < 100; i++) {
    _ideas[i] = "Default";
  }
}

Brain::Brain(const Brain &brain) {
  std::cout << "Brain: Copy constructor called" << std::endl;
  *this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
  std::cout << "Brain: Copy assign operator called" << std::endl;
  if (this != &brain) {
    for (int i = 0; i < 100; i++) {
      this->_ideas[i] = brain._ideas[i];
    }
  }
  return (*this);
}

Brain::~Brain() {
  std::cout << "Brain: Default destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const { return (this->_ideas[i]); }

