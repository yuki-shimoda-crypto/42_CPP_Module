#ifndef CONTACT_CPP
#define CONTACT_CPP

#include <string>

class Contact {
public:
  enum Field {
    FIRSTNAME,
    LASTNAME,
    NICKNAME,
    PHONE_NUM,
    DARKEST_SEC,
  };
  void setContact(const std::string &str, const Field &field);
  const std::string &getContact(const Field &field) const;
  static std::string getFieldName(const Field &field);

private:
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _phonenum;
  std::string _darkest_sec;
};

#endif
