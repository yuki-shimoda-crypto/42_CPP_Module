#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Default"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150){};

AForm::AForm(const std::string &name)
    : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150){};

AForm::AForm(const int gradeToSign, const int gradeToExecute)
    : _name("Default"), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
    throw GradeTooLowException();
  }
};

AForm::AForm(const std::string &name, const int gradeToSign,
             const int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
    throw GradeTooLowException();
  }
};

AForm::AForm(const AForm &form)
    : _name(form.getName()), _signed(form.getSign()),
      _gradeToSign(form.getGradeToSign()),
      _gradeToExecute(form.getGradeToExecute()){};

AForm &AForm::operator=(const AForm &form) {
  if (this != &form) {
    this->_signed = form.getSign();
  }
  return (*this);
}

AForm::~AForm(){};

const std::string &AForm::getName() const { return (this->_name); }

bool AForm::getSign() const { return (this->_signed); }

int AForm::getGradeToSign() const { return (this->_gradeToSign); }

int AForm::getGradeToExecute() const { return (this->_gradeToExecute); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->getGradeToSign()) {
    throw GradeTooLowException();
  }
  this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw() {
  return ("Form not signed");
}

const char *AForm::NotOpenException::what() const throw() {
  return ("File cannot open");
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "AForm name: " << form.getName() << std::endl
     << "AForm grade to sign: " << form.getGradeToSign() << std::endl
     << "AForm grade to execute: " << form.getGradeToExecute();
  return (os);
};
