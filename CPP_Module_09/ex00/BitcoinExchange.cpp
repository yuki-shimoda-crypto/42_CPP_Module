#include "BitcoinExchange.hpp"

// public

Btc::Btc() { inputDatabase(); }

Btc::Btc(const Btc &btc)
    : _database(btc._database) {}

Btc &Btc::operator=(const Btc &btc) {
  if (this != &btc) {
    this->_database = std::map<std::string, std::string>(btc._database);
  }
  return (*this);
}

Btc::~Btc() {}

bool Btc::isValidDate(const std::string &dateStr) {
  int year, month, day;
  char delim1, delim2;

  std::istringstream iss(dateStr);
  iss >> year >> delim1 >> month >> delim2 >> day;

  if (iss.fail() || delim1 != '-' || delim2 != '-' || iss.peek() != EOF) {
    return (false);
  }

  if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
    return (false);
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day < 1 || 30 < day) {
      return (false);
    }
  } else if (month == 2) {
    if (day < 1 || 28 < day) {
      return (false);
    }
  }
  return (true);
}

bool Btc::isValidValue(const std::string &valueStr) {
  double price;
  std::istringstream iss(valueStr);
  iss >> price;

  if (iss.fail() || iss.peek() != EOF || price < 0) {
    return (false);
  }
  return (true);
}

void Btc::checkOpen(const std::ifstream &file, const std::string &fileName) {
  if (!file.is_open()) {
    std::cerr << "Error: could not open " << fileName << "." << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void Btc::checkFirstLine(const std::string &line, const std::string &str,
                    const std::string &fileName) {
  if (line != str) {
    std::cerr << "Error: The first line of " << fileName << " should be '"
              << str << "'" << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

bool  Btc::hasSeparator(const std::string::size_type &pos,
                  const std::string::size_type &expectedPos) {
  if (pos == std::string::npos || pos != expectedPos) {
    return (false);
  }
  return (true);
}

std::map<std::string, std::string>::const_iterator Btc::find(const std::string &key) const {
  return (this->_database.find(key));
}

std::map<std::string, std::string>::const_iterator Btc::lower_bound(const std::string &key) const {
  return (this->_database.lower_bound(key));
}

std::map<std::string, std::string>::const_iterator Btc::end() const {
  return (this->_database.end());
}

// private

void Btc::inputDatabase() {
  std::string fileName = BTC_DATA;
  std::string line;
  std::string key;
  std::string value;
  std::string::size_type pos;
  std::size_t lineCount = 0;
  std::ifstream btcData(fileName.c_str(), std::ios_base::in);

  
  Btc::checkOpen(btcData, fileName);

  while (std::getline(btcData, line)) {

    if (lineCount == 0) {
      Btc::checkFirstLine(line, "date,exchange_rate", fileName);
      lineCount++;
      continue ;
    }

    pos = line.find(",");


    if (!Btc::hasSeparator(pos, 10)) {
      printErrorInvalidData(lineCount);
      std::exit(EXIT_FAILURE);
    }

    key = line.substr(0, pos);
    value = line.substr(pos + 1);
    if (lineCount != 0 && !isValidDate(key)) {
      printErrorInvalidDate(key);
      std::exit(EXIT_FAILURE);
    }
    if (lineCount != 0 && !isValidValue(value)) {
      printErrorInvalidValue(value);
      std::exit(EXIT_FAILURE);
    }

    this->_database[key] = value;

    lineCount++;
  }

  if (lineCount == 0) {
    std::cerr << "Error: " << fileName << " is empty." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  btcData.close();
}

void Btc::printErrorInvalidData(std::size_t lineCount) const {
  std::cerr << "Error: Invalid data format.\n"
            << "Details: The line '" << lineCount + 1
            << "' does not follow the correct format 'YYYY-MM-DD,value'.\n"
            << "Solution: Please ensure the data is entered in the "
               "'YYYY-MM-DD,value' format.\n";
}

void Btc::printErrorInvalidDate(const std::string &invalidDate) const {
  std::cerr << "Error: Invalid date format.\n"
            << "Details: '" << invalidDate << "' is not a valid date. "
            << "Months should be between 1 and 12, and days should be within "
               "the maximum days of the month.\n"
            << "Solution: Please enter the date in the 'YYYY-MM-DD' format "
               "using an existing year, month, and day.\n";
}

void Btc::printErrorInvalidValue(const std::string &invalidValue) const {
  std::cerr << "Error: Invalid value provided.\n"
            << "Details: '" << invalidValue << "' is not a valid value. "
            << "Solution: Please enter a positive number in float format.\n";
}
