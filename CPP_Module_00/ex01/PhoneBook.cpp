#include "PhoneBook.hpp"
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : _index(0) {}

void PhoneBook::add(void) {
  std::string str;
  std::size_t field = 0;
  bool is_valid_input = true;

  while (field <= Contact::DARKEST_SEC) {
    std::cout << "ADD ("
              << Contact::getFieldName(static_cast<Contact::Field>(field))
              << "): ";
    std::getline(std::cin, str);
    if (std::cin.eof() || std::cin.fail()) {
      _handleCinFailure();
      return;
    }
    if (str.empty()) {
      is_valid_input = false;
      std::cout << "The "
                << Contact::getFieldName(static_cast<Contact::Field>(field))
                << " field cannot be empty. Please enter a value." << std::endl;
    }
    if (field == Contact::PHONE_NUM && !_validatePhoneNumber(str)) {
      is_valid_input = false;
    }
    if (!is_valid_input) {
      is_valid_input = true;
      continue;
    }
    _contacts[(this->_index) % 8].setContact(
        str, static_cast<Contact::Field>(field));
    field++;
  }
  this->_index += 1;
  return;
}

void PhoneBook::search() const {
  std::string str;
  int index = 0;

  if (this->_index == 0) {
    std::cout << "No contacts available" << std::endl;
    return;
  }
  for (int i = 0; i < std::min(this->_index, 8); i++) {
    this->_displayContacts(i, Contact::NICKNAME);
  }
  while (1) {
    std::cout << "SEARCH: Please enter a contact index (0-"
              << std::min(this->_index - 1, 7) << "): ";
    std::getline(std::cin, str);
    if (std::cin.eof() || std::cin.fail()) {
      _handleCinFailure();
      return;
    }
    try {
      index = PhoneBook::_stoi(str);
      if (index < 0 || std::min(this->_index - 1, 7) < index) {
        throw std::out_of_range("");
      }
    } catch (const std::invalid_argument &e) {
      std::cout << "Invalid input, Please enter a number." << std::endl;
      continue;
    } catch (const std::out_of_range &e) {
      std::cout << "Index out of range. Please enter a number between 0-"
                << std::min(this->_index - 1, 7) << "." << std::endl;
      continue;
    }
    break;
  }
  this->_displayContacts(index, Contact::DARKEST_SEC);
  return;
}

void PhoneBook::exit() const { std::exit(0); }

int PhoneBook::_stoi(const std::string &str) {
  int sign = 1;
  long num = 0;
  size_t i = 0;

  if (str.empty()) {
    throw std::invalid_argument("stoi");
  }
  while (std::isspace(str[i])) {
    i++;
  }
  if (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-') {
      sign *= -1;
    }
    i++;
  }
  if (str.size() <= i || !std::isdigit(static_cast<unsigned char>(str[i]))) {
    throw std::invalid_argument("stoi");
  }
  while (std::isdigit(static_cast<unsigned char>(str[i]))) {
    num = num * 10 + (str[i] - '0');
    if ((sign == 1 && INT_MAX < num) || (sign == -1 && num * sign < INT_MIN)) {
      throw std::out_of_range("stoi");
    }
    i++;
  }
  return (static_cast<int>(num * sign));
}

void PhoneBook::_displayContacts(int index, int field) const {
  std::string contact;

  std::cout << std::setw(10) << index << "|";
  for (int i = 0; i <= field; i++) {
    contact = _contacts[index].getContact(static_cast<Contact::Field>(i));
    if (10 < contact.size()) {
      contact = contact.substr(0, 9) + ".";
    }
    std::cout << std::setw(10)
              << contact
              << "|";
  }
  std::cout << std::endl;
}

void PhoneBook::_handleCinFailure() const {
  std::cin.clear();
  std::clearerr(stdin);
  std::cout << std::endl;
}

bool PhoneBook::_validatePhoneNumber(const std::string &phone) const {
  for (std::size_t i = 0; i < phone.size(); i++) {
    if (!std::isdigit(static_cast<unsigned char>(phone[i]))) {
      std::cout << "Invalid input, Please enter a number." << std::endl;
      return (false);
    }
  }
  return (true);
}
