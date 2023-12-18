#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("P_Form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &s_form)
    : AForm(s_form) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &s_form) {
  if (this != &s_form) {
    AForm::operator=(s_form);
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (this->getSign() == false) {
    throw NotSignedException();
  } else if (this->getGradeToExecute() < executor.getGrade()) {
    throw GradeTooLowException();
  }
  std::cout << this->getName() << "has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
