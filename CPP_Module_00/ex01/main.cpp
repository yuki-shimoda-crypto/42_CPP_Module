#include "PhoneBook.hpp"
#include <iostream>

int main(void) {
  std::string command;
  PhoneBook phonebook;

  while (1) {
    std::cout << "Please enter a command (ADD, SEARCH, or EXIT): ";
    std::getline(std::cin, command);
    if (std::cin.eof() || std::cin.fail()) {
      std::cout << std::endl;
      return (0);
    }
    if (command == "ADD") {
      phonebook.add();
    } else if (command == "SEARCH") {
      phonebook.search();
    } else if (command == "EXIT") {
      phonebook.exit();
    } else {
      std::cout << "Invalid command. Please enter a valid command (ADD, "
                   "SEARCH, or EXIT)."
                << std::endl;
    }
  }
}
