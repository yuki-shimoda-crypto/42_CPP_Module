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

//
