#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &s_form);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &s_form);
  ~RobotomyRequestForm();
  void execute(Bureaucrat const &executor) const;

private:
};

#endif
