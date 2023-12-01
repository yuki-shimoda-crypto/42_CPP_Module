#include "Harl.hpp"

int main(void) {
  Harl harl;

  std::cout << "input \"\"" << std::endl;
  harl.complain("");
  std::cout << std::endl;

  std::cout << "input DEBUG" << std::endl;
  harl.complain("DEBUG");
  std::cout << std::endl;
}
