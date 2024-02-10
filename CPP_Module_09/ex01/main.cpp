#include "RPN.hpp"

int main(int argc, const char *argv[]) {
  RpnCalculator rpn;

  if (argc != 2) {
    std::cerr << "Usage ./RPN \"1 1 +\"" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  try {
    std::cout << rpn.evaluate(argv[1]) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (1);
  }
  return (0);
}
