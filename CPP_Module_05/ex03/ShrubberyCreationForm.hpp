#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &s_form);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s_form);
  ~ShrubberyCreationForm();
  void execute(Bureaucrat const &executor) const;

private:
};

#endif
