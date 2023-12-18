#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("R_Form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s_form)
    : AForm(s_form) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &s_form) {
  if (this != &s_form) {
    AForm::operator=(s_form);
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (this->getSign() == false) {
    throw NotSignedException();
  } else if (this->getGradeToExecute() < executor.getGrade()) {
    throw GradeTooLowException();
  }
  std::cout << "Drilling noises: gagagagagaga" << std::endl;
  std::srand(std::time(0));
  if (std::rand() % 2 == 0) {
    std::cout << "Success: " << this->getName() << "has been robotomized."
              << std::endl;
  } else {
    std::cout << "Fail: " << this->getName() << "has not been robotomized."
              << std::endl;
  }
}
