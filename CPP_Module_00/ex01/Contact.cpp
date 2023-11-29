#include "Contact.hpp"

void Contact::setContact(const std::string &str, const Contact::Field &field) {
  if (field == FIRSTNAME) {
    this->_firstname = str;
  } else if (field == LASTNAME) {
    this->_lastname = str;
  } else if (field == NICKNAME) {
    this->_nickname = str;
  } else if (field == PHONE_NUM) {
    this->_phonenum = str;
  } else if (field == DARKEST_SEC) {
    this->_darkest_sec = str;
  }
}

const std::string &Contact::getContact(const Contact::Field &field) const {
  if (field == FIRSTNAME) {
    return (this->_firstname);
  } else if (field == LASTNAME) {
    return (this->_lastname);
  } else if (field == NICKNAME) {
    return (this->_nickname);
  } else if (field == PHONE_NUM) {
    return (this->_phonenum);
  } else if (field == DARKEST_SEC) {
    return (this->_darkest_sec);
  }
  return (std::string());
}

std::string Contact::getFieldName(const Contact::Field &field) {
  if (field == FIRSTNAME) {
    return ("first name");
  } else if (field == LASTNAME) {
    return ("last name");
  } else if (field == NICKNAME) {
    return ("nickname");
  } else if (field == PHONE_NUM) {
    return ("phone number");
  } else if (field == DARKEST_SEC) {
    return ("darkest secret");
  }
  return (std::string());
}
