#include "PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  try {
    CommandLineParser parser(argc, argv);

    std::vector<long> numVec = parser.getVector();
    std::list<long> numList = parser.getList();

    VectorMergeInsertionSort sortVec;
    ListMergeInsertionSort sortList;

    //display
    sortVec.displayInput(numVec);
//    sortList.displayInput(numList);
    
    //sort
    std::size_t timeVec = sortVec.sortAndMeasure(numVec);
    std::size_t timeList = sortList.sortAndMeasure(numList);
    
    //display
    sortVec.displayOutput(numVec);
//    sortList.displayOutput(numList);

    // time
    sortVec.displayTime(numVec, "std::vector", timeVec);
    sortList.displayTime(numList, "std::list", timeList);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return (0);
}
