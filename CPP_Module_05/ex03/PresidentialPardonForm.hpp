#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &s_form);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &s_form);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const &executor) const;

private:
};

#endif
