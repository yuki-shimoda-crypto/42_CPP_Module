#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const int n) : _name("Default"), _grade(n) {
  if (this->_grade < 1) {
    throw GradeTooHighException();
  }
  if (this->_grade > 150) {
    throw GradeTooLowException();
  }
};

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

void Bureaucrat::gradeUp() {
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade too low");
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << this->getName() << " couldn’t sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
      form.execute(*this);
      std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const AForm::NotSignedException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
      std::cout << e.what() << std::endl;
    } catch (const AForm::NotOpenException &e) {
      std::cout << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (os);
};
