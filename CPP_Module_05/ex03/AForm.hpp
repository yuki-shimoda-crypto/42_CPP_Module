#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string &name);
  AForm(const int gradeToSign, const int gradeToExecute);
  AForm(const std::string &name, const int gradeToSign,
        const int gradeToExecute);
  AForm(const AForm &form);
  AForm &operator=(const AForm &form);
  virtual ~AForm();

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
  class NotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };
  class NotOpenException : public std::exception {
  public:
    const char *what() const throw();
  };
  class MakeFormException : public std::exception {
  public:
    const char *what() const throw();
  };

  virtual void execute(Bureaucrat const &executor) const = 0;

private:
  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
