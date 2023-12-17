#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const std::string &name);
  Bureaucrat(const std::string &name, const int n);
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  ~Bureaucrat();
  const std::string &getName() const;
  int getGrade() const;
  void gradeUP();
  void gradeDown();
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
  int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
