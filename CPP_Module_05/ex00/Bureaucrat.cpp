#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const int n)
    : _name(name), _grade(n) {
  if (this->_grade < 1) {
    throw GradeTooHighException();
  }
  if (this->_grade > 150) {
    throw GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  if (this != &bureaucrat) {
    this->_grade = bureaucrat.getGrade();
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::gradeUP() {
  if (this->_grade <= 1) {
    throw GradeTooHighException();
  }
  this->_grade--;
}

void Bureaucrat::gradeDown() {
  if (this->_grade >= 150) {
    throw GradeTooLowException();
  }
  this->_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (os);
};
