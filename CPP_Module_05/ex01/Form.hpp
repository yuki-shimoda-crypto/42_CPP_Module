#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string &name);
  Form(const int gradeToSign, const int gradeToExecute);
  Form(const std::string &name, const int gradeToSign,
       const int gradeToExecute);
  Form(const Form &form);
  Form &operator=(const Form &form);
  ~Form();

  const std::string &getName() const;
  bool getSign() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
