#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

class Btc {
public:
  Btc();
  Btc(const Btc &btc);
  Btc &operator=(const Btc &btc);
  ~Btc();
  void inputBtcData();
  double getBtcPrice(const std::string &date);

private:
  std::map<std::string, std::string> _btcData;
  std::list<std::string> _inputData;
  void _inputBtcData();
  bool isValidDate(const std::string &dateStr);
  bool isValidValue(const std::string &valueStr);
  void printErrorInvalidData(std::size_t lineCount) const;
  void printErrorInvalidDate(const std::string &invalidValue) const;
  void printErrorInvalidValue(const std::string &invalidValue) const;
};

#endif
