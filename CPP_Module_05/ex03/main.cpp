#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  {
    std::cout << "------------------------------------------" << std::endl;
    Bureaucrat a("Bureaucrat A", 42);
    Intern someRandomIntern;
    AForm *rrf;

    try {
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
      a.signForm(*rrf);
      a.executeForm(*rrf);
      delete rrf;
    } catch (const AForm::MakeFormException &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "------------------------------------------" << std::endl;
    Bureaucrat a("Bureaucrat A", 42);
    Intern someRandomIntern;
    AForm *rrf;

    try {
      rrf = someRandomIntern.makeForm("test", "Bender");
      a.signForm(*rrf);
      a.executeForm(*rrf);
      delete rrf;
    } catch (const AForm::MakeFormException &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
