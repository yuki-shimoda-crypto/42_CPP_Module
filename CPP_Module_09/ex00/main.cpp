#include "BitcoinExchange.hpp"

int main(int argc, const char *argv[]) {
  Btc btc;

  std::string line;
  std::string key;
  std::string value;
  std::string::size_type pos;
  std::size_t lineCount = 0;

  if (argc != 2) {
    std::cerr << "Usage: ./btc filename" << std::endl;
    return (1);
  }

  std::ifstream inputFile(argv[1], std::ios_base::in);

  Btc::checkOpen(inputFile, argv[1]);

  while (std::getline(inputFile, line)) {

    if (lineCount == 0) {
      Btc::checkFirstLine(line, "date | value", argv[1]);
      lineCount++;
      continue;
    }

    pos = line.find("|");

    if (!Btc::hasSeparator(pos, 11)) {
      std::cout << "Error: bad input = " << line << std::endl;
      lineCount++;
      continue;
    }

    key = line.substr(0, pos - 1);
    value = line.substr(pos + 1);

    if (!Btc::isValidDate(key)) {
      std::cout << "Error: invalid date = " << key << std::endl;
      lineCount++;
      continue;
    }
    if (!Btc::isValidValue(value)) {
      double price;
      std::istringstream iss(value);
      iss >> price;
      if (iss.fail()) {
        std::cout << "Error: not a number." << std::endl;
      } else if (iss.peek() != EOF) {
        std::cout << "Error: too much input." << std::endl;
      } else {
        std::cout << "Error: not a positive number." << std::endl;
      }
      lineCount++;
      continue;
    } else if (1000 < std::stod(value)) {
      std::cout << "Error: too large a number." << std::endl;
      lineCount++;
      continue;
    }

    std::map<std::string, std::string>::const_iterator it = btc.find(key);
    if (it != btc.end()) {
      std::cout << key << " =>" << value << " = "
                << std::stod(value) * std::stod(it->second) << std::endl;
    } else {
      it = btc.lower_bound(key);
      if (it != btc.begin()) {
        it--;
      } else {
        std::cout << "Error: invalid date. " << it->first << std::endl;
        lineCount++;
        continue;
      }
      std::cout << key << " =>" << value << " = "
                << std::stod(value) * std::stod(it->second) << std::endl;
    }
    lineCount++;
  }

  if (lineCount == 0) {
    std::cerr << "Error: " << argv[1] << " is empty." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  inputFile.close();
  return (0);
}
