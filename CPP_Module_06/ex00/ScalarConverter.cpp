#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter &convertor) {
  *this = convertor;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &convertor) {
  if (this != &convertor) {
  }
  return (*this);
}

ScalarConverter::~ScalarConverter(){};

void ScalarConverter::convert(const std::string &literal) {
  ScalarType scalarType = getType(literal);

  if (scalarType == _CHAR) {
    convertFromChar(literal[0]);
  } else if (scalarType == _INT) {
    try {
      convertFromInt(std::stoi(literal));
    } catch (const std::out_of_range &e) {
      std::cout << "Error: Number out of range for int conversion."
                << std::endl;
    }
  } else if (scalarType == _FLOAT) {
    if (isPseudoLiterals(literal)) {
      printPseudoLiterals(scalarType, literal);
    } else {
      try {
        convertFromFloat(std::stof(literal));
      } catch (const std::out_of_range &e) {
        std::cout << "Error: Number out of range for float conversion."
                  << std::endl;
      }
    }
  } else if (scalarType == _DOUBLE) {
    if (isPseudoLiterals(literal)) {
      printPseudoLiterals(scalarType, literal);
    } else {
      try {
        convertFromDouble(std::stod(literal));
      } catch (const std::out_of_range &e) {
        std::cout << "Error: Number out of range for double conversion."
                  << std::endl;
      }
    }
  } else {
    std::cout << "Please input char, int, float, or double" << std::endl;
  }
}

void ScalarConverter::convertFromChar(const char c) {
  std::cout << "char: " << c << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const int num) {
  if (std::numeric_limits<char>::min() <= num &&
      num <= std::numeric_limits<char>::max() && std::isprint(num))
    std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(num) << std::endl;
  std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const float f) {
  if (std::numeric_limits<char>::min() <= f &&
      f <= std::numeric_limits<char>::max() && std::isprint(f))
    std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(f) << std::endl;
  std::cout << "float: " << static_cast<float>(f) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void ScalarConverter::convertFromDouble(const double d) {
  if (std::numeric_limits<char>::min() <= d &&
      d <= std::numeric_limits<char>::max() && std::isprint(d))
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(d) << std::endl;
  std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
}

ScalarType ScalarConverter::getType(const std::string &literal) {
  if (isChar(literal)) {
    return (_CHAR);
  } else if (isInt(literal)) {
    return (_INT);
  } else if (isFloat(literal)) {
    return (_FLOAT);
  } else if (isDouble(literal)) {
    return (_DOUBLE);
  } else {
    return (_ERROR);
  }
}

bool ScalarConverter::isChar(const std::string &literal) {
  if (literal.size() == 1 && !std::isdigit(literal[0])) {
    return (true);
  }
  return (false);
}

bool ScalarConverter::isInt(const std::string &literal) {
  std::size_t i = 0;

  if (literal[i] == '-' || literal[i] == '+') {
    i++;
  }
  for (; i < literal.size(); i++) {
    if (!std::isdigit(literal[i])) {
      return (false);
    }
  }
  return (true);
}

bool ScalarConverter::isFloat(const std::string &literal) {
  std::size_t n = literal.size();
  std::size_t numPoint = 0;
  std::size_t i = 0;

  if (literal[n - 1] != 'f') {
    return (false);
  }
  if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
    return (true);
  }
  if (literal[i] == '-' || literal[i] == '+') {
    i++;
  }
  for (; i < n - 1; i++) {
    if (!std::isdigit(literal[i]) && literal[i] != '.') {
      return (false);
    }
    if (literal[i] == '.') {
      numPoint += 1;
    }
  }
  if (numPoint != 1) {
    return (false);
  }
  return (true);
}

bool ScalarConverter::isDouble(const std::string &literal) {
  std::size_t n = literal.size();
  std::size_t numPoint = 0;
  std::size_t i = 0;

  if (literal == "-inf" || literal == "+inf" || literal == "nan") {
    return (true);
  }
  if (literal[i] == '-' || literal[i] == '+') {
    i++;
  }
  for (; i < n; i++) {
    if (!std::isdigit(literal[i]) && literal[i] != '.') {
      return (false);
    }
    if (literal[i] == '.') {
      numPoint += 1;
    }
  }
  if (numPoint != 1) {
    return (false);
  }
  return (true);
}

bool ScalarConverter::isPseudoLiterals(const std::string &literal) {
  if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
      literal == "-inff" || literal == "+inff" || literal == "nanf") {
    return (true);
  } else {
    return (false);
  }
}

void ScalarConverter::printPseudoLiterals(const ScalarType type,
                                          const std::string &literal) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (type == _FLOAT) {
    std::cout << "float: " << literal << std::endl;
    std::cout << "double: " << literal.substr(0, literal.length() - 1)
              << std::endl;
  } else if (type == _DOUBLE) {
    std::cout << "float: " << literal + "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
  }
}
