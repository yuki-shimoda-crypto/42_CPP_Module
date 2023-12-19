#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>

enum ScalarType {
  _CHAR,
  _INT,
  _FLOAT,
  _DOUBLE,
  _ERROR,
};

class ScalarConverter {
public:
  static void convert(const std::string &literal);

  static ScalarType getType(const std::string &literal);

  static bool isChar(const std::string &literal);
  static bool isInt(const std::string &literal);
  static bool isFloat(const std::string &literal);
  static bool isDouble(const std::string &literal);

  static void convertFromChar(const char c);
  static void convertFromInt(const int num);
  static void convertFromFloat(const float f);
  static void convertFromDouble(const double d);

  static bool isPseudoLiterals(const std::string &literal);
  static void printPseudoLiterals(const ScalarType type, const std::string &literal);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &convertor);
  ScalarConverter &operator=(const ScalarConverter &convertor);
  ~ScalarConverter();
};
#endif
