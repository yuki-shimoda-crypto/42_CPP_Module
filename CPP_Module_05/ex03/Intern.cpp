#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &intern) { *this = intern; };

Intern &Intern::operator=(const Intern &intern) {
  if (this != &intern) {
  }
  return (*this);
}

Intern::~Intern(){};

AForm *Intern::makeForm(std::string name, std::string target) {
  int i = 0;
  AForm *obj = NULL;
  i += (name == "shrubbery creation") * 1 + (name == "robotomy request") * 2 +
       (name == "presidential pardon") * 3;
  switch (i) {
  case 1:
    obj = new ShrubberyCreationForm(target);
    break;
  case 2:
    obj = new RobotomyRequestForm(target);
    break;
  case 3:
    obj = new PresidentialPardonForm(target);
    break;
  default:
    throw AForm::MakeFormException();
  }
  std::cout << "Intern creates " << name << std::endl;
  return (obj);
}
