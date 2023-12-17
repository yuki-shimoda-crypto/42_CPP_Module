#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  {
    Bureaucrat a("Bureaucrat A", 150);
    Form b("Form B", 150, 150);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << std::endl;
    a.signForm(b);
    std::cout << std::endl;
    std::cout << std::endl;
  }
  {
    Bureaucrat a("Bureaucrat A", 150);
    Form b("Form B", 149, 149);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << std::endl;
    a.signForm(b);
    std::cout << std::endl;
    std::cout << std::endl;
  }
}
