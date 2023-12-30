#include "BitcoinExchange.hpp"

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
            << "Solution: Please enter a positive number in double format.\n";
}

bool Btc::isValidDate(const std::string &dateStr) {
  int year, month, day;
  char delim1, delim2;

  std::istringstream iss(dateStr);
  iss >> year >> delim1 >> month >> delim2 >> day;

  if (iss.fail() || delim1 != '-' || delim2 != '-' || iss.peek() != EOF) {
    printErrorInvalidDate(dateStr);
    return (false);
  }

  if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
    printErrorInvalidDate(dateStr);
    return (false);
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day < 1 || 30 < day) {
      printErrorInvalidDate(dateStr);
      return (false);
    }
  } else if (month == 2){
    if (day < 1 || 28 < day) {
      printErrorInvalidDate(dateStr);
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
    printErrorInvalidValue(valueStr);
    return (false);
  }
  return (true);
}

void Btc::inputBtcData() {
  std::string dataFileName = "data.csv";

  std::ifstream btcData(dataFileName.c_str(), std::ios_base::in);

  if (!btcData.is_open()) {
    std::cerr << "Error: " << dataFileName << " isn't found." << std::endl;
    std::exit(EXIT_FAILURE);
  }

   std::string::size_type pos;
   std::string line;
   std::size_t lineCount = 0;
  while (std::getline(btcData, line)) {
    if (lineCount == 0 && line != "date,exchange_rate") {
      std::cerr << "Error: The first line of " << dataFileName
                << " should be 'date,exchange_rate'" << std::endl;
      std::exit(EXIT_FAILURE);
    }
    pos = line.find(",");
    if (pos == std::string::npos || (pos != 10 && lineCount != 0)) {
      printErrorInvalidData(lineCount);
      std::exit(EXIT_FAILURE);
    }
    if (lineCount != 0 && !isValidDate(line.substr(0, pos))) {
      std::exit(EXIT_FAILURE);
    }
    if (lineCount != 0 && !isValidValue(line.substr(pos + 1))) {
      std::exit(EXIT_FAILURE);
    }
    lineCount++;
    std::cout << line << std::endl;
  }
  if (lineCount == 0) {
    std::cerr << "Error: " << dataFileName << " is empty." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  btcData.close();
}

Btc::Btc() { inputBtcData(); }

Btc::Btc(const Btc &btc) : _btcData(btc._btcData), _inputData(btc._inputData) {}

// Btc &Btc::operator=(const Btc &btc) {
//   if (this != &btc) {
//     this->_btcData = std::list<std::string>(btc._btcData);
//     this->_inputData = std::list(btc._inputData);
//   }
// }

Btc::~Btc() {}
