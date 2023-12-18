#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &intern);
  Intern &operator=(const Intern &intern);
  ~Intern();

  AForm *makeForm(std::string name, std::string target);

private:
};

#endif
