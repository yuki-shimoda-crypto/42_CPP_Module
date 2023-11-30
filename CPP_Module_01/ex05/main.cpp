#include "Harl.hpp"

int main(void) {
  Harl harl;

  std::cout << "input \"\"" << std::endl;
  harl.complain("");
  std::cout << std::endl;

  std::cout << "input DEBUG" << std::endl;
  harl.complain("DEBUG");
  std::cout << std::endl;

  std::cout << "input INFO" << std::endl;
  harl.complain("INFO");
  std::cout << std::endl;

  std::cout << "input WARNING" << std::endl;
  harl.complain("WARNING");
  std::cout << std::endl;

  std::cout << "input ERROR" << std::endl;
  harl.complain("ERROR");
  std::cout << std::endl;
}
