#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("S_Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &s_form)
    : AForm(s_form) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s_form) {
  if (this != &s_form) {
    AForm::operator=(s_form);
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  std::string filename = this->getName() + "_shrubbery";
  std::ofstream ofs;

  if (this->getSign() == false) {
    throw NotSignedException();
  } else if (this->getGradeToExecute() < executor.getGrade()) {
    throw GradeTooLowException();
  }
  ofs.open(filename.c_str());
  if (!ofs.is_open()) {
    throw NotOpenException();
  }
  ofs << "   /\\                        " << std::endl
      << "  /  \\                       " << std::endl
      << " /    \\                      " << std::endl
      << "/______\\                     " << std::endl
      << "  ||||                        " << std::endl;
  ofs.close();
}
