#include "PmergeMe.hpp"

// CommandLineParser

// public
CommandLineParser::CommandLineParser(const int argc, const char *argv[]) {
  parseArgument(argc, argv);
}

CommandLineParser::~CommandLineParser() {}

const std::vector<long> &CommandLineParser::getVector() const {
  return (this->_numVec);
}

const std::list<long> &CommandLineParser::getList() const {
  return (this->_numList);
}

// private
void CommandLineParser::parseArgument(const int argc, const char *argv[]) {
  long num;

  if (argc == 1) {
    handleEmptyInput();
  }

  for (long i = 1; i < argc; i++) {
    std::istringstream iss(argv[i]);
    iss >> num;
    if (iss.fail() || iss.peek() != EOF) {
      handleInvalidInput(argv[i]);
    } else if (num <= 0) {
      handleMinusValue(argv[i]);
    }
    _numVec.push_back(num);
    _numList.push_back(num);
  }
}

void CommandLineParser::handleEmptyInput() const {
  throw std::logic_error("Empty input.");
}

void CommandLineParser::handleInvalidInput(const std::string &str) const {
  throw std::invalid_argument(std::string("Invalid input: ") + str);
}

void CommandLineParser::handleMinusValue(const std::string &str) const {
  throw std::invalid_argument(std::string("Minus or Zero value: ") + str);
}

CommandLineParser::CommandLineParser() {}

CommandLineParser::CommandLineParser(const CommandLineParser &parser) {
  (void)parser;
}

CommandLineParser &
CommandLineParser::operator=(const CommandLineParser &parser) {
  (void)parser;
  return (*this);
}

// VectorMergeInsertionSort

// public
VectorMergeInsertionSort::VectorMergeInsertionSort() {}
VectorMergeInsertionSort::~VectorMergeInsertionSort() {}

// private
void VectorMergeInsertionSort::sort(std::vector<long> &container) {
  if (container.size() <= 1) {
    return;
  }

  std::vector<long> smaller, larger;

  // first pairs of elements are compared;
  for (std::size_t i = 0; i < container.size(); i += 2) {
    if (i + 1 < container.size()) {
      if (container.at(i) < container.at(i + 1)) {
        smaller.push_back(container.at(i));
        larger.push_back(container.at(i + 1));
      } else {
        smaller.push_back(container.at(i + 1));
        larger.push_back(container.at(i));
      }
    } else {
      larger.push_back(container.at(i));
    }
  }

  // second step the larger elements are sorted recursively;
  sort(larger);

  // last step the elements belonging to the smaller half are inserted into the
  // already sorted larger half using binary insertion.
  for (std::size_t i = 0; i < smaller.size(); i++) {
    std::vector<long>::iterator insertPos =
        binarySearchInsertPosition(larger, smaller.at(i));
    larger.insert(insertPos, smaller.at(i));
  }

  container = larger;
}

VectorMergeInsertionSort::VectorMergeInsertionSort(
    const VectorMergeInsertionSort &sort)
    : MergeInsertionSort(sort) {
  (void)sort;
}

VectorMergeInsertionSort &
VectorMergeInsertionSort::operator=(const VectorMergeInsertionSort &sort) {
  if (this != &sort) {
  }
  return (*this);
}

// ListMergeInsertionSort

// public
ListMergeInsertionSort::ListMergeInsertionSort() {}
ListMergeInsertionSort::~ListMergeInsertionSort() {}

// private
void ListMergeInsertionSort::sort(std::list<long> &container) {
  std::cout << "list sort" << std::endl;
  (void)container;
}

ListMergeInsertionSort::ListMergeInsertionSort(
    const ListMergeInsertionSort &sort)
    : MergeInsertionSort(sort) {
  (void)sort;
}

ListMergeInsertionSort &
ListMergeInsertionSort::operator=(const ListMergeInsertionSort &sort) {
  if (this != &sort) {
  }
  return (*this);
}
