#include "PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  try {
    CommandLineParser parser(argc, argv);

    std::vector<long> numVec = parser.getVector();
    std::list<long> numList = parser.getList();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return (0);
}
