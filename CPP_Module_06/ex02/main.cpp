#include "functions.hpp"

int main(void) {
  Base *base = generate();
  std::cout << std::endl;

  identify(base);
  std::cout << std::endl;
  identify(*base);

  delete base;
}
