#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

class CommandLineParser {
public:
  CommandLineParser(const int argc, const char *argv[]);
  ~CommandLineParser();

  const std::vector<long> &getVector() const;
  const std::list<long> &getList() const;

private:
  std::vector<long> _numVec;
  std::list<long> _numList;

  void parseArgument(const int argc, const char *argv[]);

  void handleEmptyInput() const;
  void handleInvalidInput(const std::string &str) const;
  void handleMinusValue(const std::string &str) const;

  CommandLineParser();
  CommandLineParser(const CommandLineParser &parser);
  CommandLineParser &operator=(const CommandLineParser &parser);
};

#endif
