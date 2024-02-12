#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

#define BTC_DATA "data.csv"

class Btc {
public:
  Btc();
  Btc(const Btc &btc);
  Btc &operator=(const Btc &btc);
  ~Btc();
  static bool isValidDate(const std::string &dateStr);
  static bool isValidValue(const std::string &valueStr);
  static void checkOpen(const std::ifstream &file, const std::string &fileName);
  static void checkFirstLine(const std::string &line, const std::string &str,
                             const std::string &fileName);
  static bool hasSeparator(const std::string::size_type &pos,
                           const std::string::size_type &expectedPos);
  static double stod(const std::string &str);
  std::map<std::string, std::string>::const_iterator
  find(const std::string &key) const;
  std::map<std::string, std::string>::const_iterator
  lower_bound(const std::string &key) const;
  std::map<std::string, std::string>::const_iterator
  upper_bound(const std::string &key) const;
  std::map<std::string, std::string>::const_iterator begin() const;
  std::map<std::string, std::string>::const_iterator end() const;

private:
  std::map<std::string, std::string> _database;
  void inputDatabase();
  void printErrorInvalidData(std::size_t lineCount) const;
  void printErrorInvalidDate(const std::string &invalidValue) const;
  void printErrorInvalidValue(const std::string &invalidValue) const;
};

#endif
