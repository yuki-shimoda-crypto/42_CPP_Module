#include "ScalarConverter.hpp"

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./convert <string>" << std::endl;
    return (1);
  } 
  ScalarConverter::convert(argv[1]);
  return (0);
}
