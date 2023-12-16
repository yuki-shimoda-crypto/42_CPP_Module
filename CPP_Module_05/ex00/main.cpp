#include "Bureaucrat.hpp"

int main() {
  {
    Bureaucrat a;
    std::cout << a << std::endl;

    try {
      std::cout << "gradeUP a" << std::endl;
      a.gradeUP();
      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "gradeDown a" << std::endl;
      a.gradeDown();
      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "gradeDown a" << std::endl;
      a.gradeDown();
      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << std::endl;
    Bureaucrat b("two", 1);
    std::cout << b << std::endl;

    try {
      std::cout << "gradeUP b" << std::endl;
      b.gradeUP();
      std::cout << b << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << "gradeDown b" << std::endl;
      b.gradeDown();
      std::cout << b << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}
