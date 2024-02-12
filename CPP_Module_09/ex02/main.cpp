#include "PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  try {
    CommandLineParser parser(argc, argv);

    std::vector<long> numVec = parser.getVector();
    std::list<long> numList = parser.getList();

    VectorMergeInsertionSort sortVec;
    ListMergeInsertionSort sortList;

    // display input
    sortVec.displayInput(numVec);
    // sortList.displayInput(numList);

    // sort
    long timeVec = sortVec.sortAndMeasure(numVec);
    long timeList = sortList.sortAndMeasure(numList);

    // display output
    sortVec.displayOutput(numVec);
    // sortList.displayOutput(numList);

    // display time
    sortVec.displayTime(numVec, "std::vector", timeVec);
    sortList.displayTime(numList, "std::list", timeList);

    //    // debug vector
    //    std::vector<long> ansVec = parser.getVector();
    //    std::sort(ansVec.begin(), ansVec.end());
    //    if (sortVec.isEqualContainer(ansVec, numVec)) {
    //      std::cout << "true" << std::endl;
    //    } else {
    //      std::cout << "false" << std::endl;
    //    }
    //
    //    // debug list
    //    std::list<long> ansList = parser.getList();
    //    ansList.sort();
    //    if (sortList.isEqualContainer(ansList, numList)) {
    //      std::cout << "true" << std::endl;
    //    } else {
    //      std::cout << "false" << std::endl;
    //    }

    //    // debug show element
    //    sortVec.showContainerElement(numVec);
    //    sortList.showContainerElement(numList);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return (0);
}
