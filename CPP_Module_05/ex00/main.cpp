#include "Bureaucrat.hpp"

int main() {
  {
    Bureaucrat a;
    std::cout << a << std::endl;

    try {
      std::cout << "gradeUp a" << std::endl;
      a.gradeUp();
      std::cout << a << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "gradeDown a" << std::endl;
      a.gradeDown();
      std::cout << a << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "gradeDown a" << std::endl;
      a.gradeDown();
      std::cout << a << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << std::endl;
    Bureaucrat b("two", 1);
    std::cout << b << std::endl;

    try {
      std::cout << "gradeUp b" << std::endl;
      b.gradeUp();
      std::cout << b << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "gradeDown b" << std::endl;
      b.gradeDown();
      std::cout << b << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
