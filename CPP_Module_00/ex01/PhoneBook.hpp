#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  void add();
  void search() const;
  void exit() const;
  static int stoi(const std::string &str);

private:
  Contact _contacts[8];
  int _index;
  void _displayConstactsAll(int index) const;
  void _displayContactsPartial(int index) const;
};

#endif
