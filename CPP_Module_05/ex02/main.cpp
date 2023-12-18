#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

  {
    // ShrubberyCreationForm: Not signed.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm: Not signed." << std::endl;
    Bureaucrat a("Bureaucrat A", 150);
    ShrubberyCreationForm sform("ShrubberyCreationForm");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // ShrubberyCreationForm: Grade too low to execute.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm: Grade too low to execute."
              << std::endl;
    Bureaucrat a("Bureaucrat A", 145);
    ShrubberyCreationForm sform("ShrubberyCreationForm");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // ShrubberyCreationForm: File cannot open.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm: File cannot open." << std::endl;
    Bureaucrat a("Bureaucrat A", 137);
    ShrubberyCreationForm sform("FileCannotOpen");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // ShrubberyCreationForm: Success
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm: Success." << std::endl;
    Bureaucrat a("Bureaucrat A", 137);
    ShrubberyCreationForm sform("ShrubberyCreationForm");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // RobotomyRequestForm: Not signed.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "RobotomyRequestForm: Not signed." << std::endl;
    Bureaucrat a("Bureaucrat A", 150);
    RobotomyRequestForm sform("RobotomyRequestForm");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // RobotomyRequestForm: Grade too low to execute.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "RobotomyRequestForm: Grade too low to execute." << std::endl;
    Bureaucrat a("Bureaucrat A", 72);
    RobotomyRequestForm sform("RobotomyRequestForm");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // RobotomyRequestForm: Success
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "RobotomyRequestForm: Success." << std::endl;
    Bureaucrat a("Bureaucrat A", 45);
    RobotomyRequestForm sform("RobotomyRequestForm");

    std::cout << a << std::endl;
    std::cout << sform << std::endl;

    a.signForm(sform);
    a.executeForm(sform);
  }

  {
    // PresidentialPardonForm: Not signed.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "PresidentialPardonForm: Not signed." << std::endl;
    Bureaucrat a("Bureaucrat A", 150);
    PresidentialPardonForm pForm("PresidentialPardonForm");

    std::cout << a << std::endl;
    std::cout << pForm << std::endl;

    a.signForm(pForm);
    a.executeForm(pForm);
  }

  {
    // PresidentialPardonForm: Grade too low to execute.
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "PresidentialPardonForm: Grade too low to execute."
              << std::endl;
    Bureaucrat a("Bureaucrat A", 25);
    PresidentialPardonForm pForm("PresidentialPardonForm");

    std::cout << a << std::endl;
    std::cout << pForm << std::endl;

    a.signForm(pForm);
    a.executeForm(pForm);
  }

  {
    // PresidentialPardonForm: Success
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "PresidentialPardonForm: Success." << std::endl;
    Bureaucrat a("Bureaucrat A", 5);
    PresidentialPardonForm pForm("PresidentialPardonForm");

    std::cout << a << std::endl;
    std::cout << pForm << std::endl;

    a.signForm(pForm);
    a.executeForm(pForm);
  }
}
