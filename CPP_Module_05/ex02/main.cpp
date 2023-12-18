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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::NotOpenException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::NotOpenException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::NotOpenException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::NotOpenException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      sform.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      pForm.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      pForm.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
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
    try {
      pForm.execute(a);
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
