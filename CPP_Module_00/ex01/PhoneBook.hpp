#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  void add();
  void search() const;
  void exit() const;

private:
  Contact _contacts[8];
  int _index;
  static int _stoi(const std::string &str);
  void _displayContacts(int index, int field) const;
  void _handleCinFailure() const;
  bool _validatePhoneNumber(const std::string &phone) const;
};

#endif
