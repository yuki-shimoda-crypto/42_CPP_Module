#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _gradeToSign(150), _gradeToExecute(150){};

Form::Form(const std::string &name)
    : _name(name), _gradeToSign(150), _gradeToExecute(150){};

Form::Form(const int gradeToSign, const int gradeToExecute)
    : _name("Default"), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
    throw GradeTooLowException();
  }
};

Form::Form(const std::string &name, const int gradeToSign,
           const int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) { throw GradeTooHighException();
  }
  if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
    throw GradeTooLowException();
  }
};

Form::Form(const Form &form)
    : _name(form.getName()), _gradeToSign(form.getGradeToSign()),
      _gradeToExecute(form.getGradeToExecute()){};

Form &Form::operator=(const Form &form) {
  if (this != &form) {
    this->_signed = form.getSign();
  }
  return (*this);
}

Form::~Form(){};

const std::string &Form::getName() const { return (this->_name); }

bool Form::getSign() const { return (this->_signed); }

int Form::getGradeToSign() const { return (this->_gradeToSign); }

int Form::getGradeToExecute() const { return (this->_gradeToExecute); }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->getGradeToSign()) {
    throw GradeTooLowException();
  }
  this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form name: " << form.getName() << std::endl
     << "Form grade to sign: " << form.getGradeToSign() << std::endl
     << "Form grade to execute: " << form.getGradeToExecute();
  return (os);
};
