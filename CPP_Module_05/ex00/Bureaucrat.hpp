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
    virtual const char *what() const throw() { return ("Grade too high"); }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return ("Grade too low"); }
  };

private:
  const std::string _name;
  int _grade;
};
class GradeTooHighException : public std::exception {
public:
  const char *what() const throw() { return "Grade too high"; }
};
class GradeTooLowException : public std::exception {
public:
  const char *what() const throw() { return "Grade too low"; }
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
