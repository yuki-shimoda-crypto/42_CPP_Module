#include "RPN.hpp"

RpnCalculator::RpnCalculator() {}

RpnCalculator::RpnCalculator(const RpnCalculator &rpnCalculator)
    : _stack(rpnCalculator._stack) {}

RpnCalculator &RpnCalculator::operator=(const RpnCalculator &rpnCalculator) {
  if (this != &rpnCalculator) {
    this->_stack = rpnCalculator._stack;
  }
  return (*this);
}

RpnCalculator::~RpnCalculator() {}

double RpnCalculator::evaluate(const std::string &input) {
  std::string::size_type pos = 0;
  std::string::size_type length = input.size();

  if (length == 0) {
    std::cerr << "Error." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  while (pos < length) {
    if (std::isdigit(static_cast<unsigned char>(input.at(pos)))) {
      this->_stack.push(input.at(pos) - '0');
    } else if (isOperator(input.at(pos))) {
      applyOperator(input.at(pos));
    } else if (isSpace(input.at(pos))) {
    } else {
      handleInvalidInput(input.at(pos));
    }
    pos++;
  }
  if (this->_stack.size() != 1) {
    handleIncompleteInput();
  }
  return (this->_stack.top());
}

// private

void RpnCalculator::applyOperator(const char op) {
  if (this->_stack.empty()) {
    handleEmptyStack();
  } else if (this->_stack.size() < 2) {
    handleIncompleteInput();
  }

  double a = this->_stack.top();
  this->_stack.pop();

  double b = this->_stack.top();
  this->_stack.pop();

  if (op == '+') {
    this->_stack.push(b + a);
  } else if (op == '-') {
    this->_stack.push(b - a);
  } else if (op == '*') {
    this->_stack.push(b * a);
  } else {
    this->_stack.push(b / a);
  }
}

bool RpnCalculator::isOperator(const char ch) const {
  if ((ch == '+') | (ch == '-') | (ch == '*') | (ch == '/')) {
    return (true);
  }
  return (false);
}

bool RpnCalculator::isSpace(const char ch) const {
  if (ch == ' ') {
    return (true);
  }
  return (false);
}

void RpnCalculator::handleEmptyStack() const {
  throw std::logic_error("Tried to apply operator to an empty stack");
}

void RpnCalculator::handleDivisionByZero() const {
  throw std::logic_error("Attempt to divide by zero");
}

void RpnCalculator::handleInvalidInput(const char ch) const {
  throw std::invalid_argument(std::string("Invalid input character: ") + ch);
}

void RpnCalculator::handleIncompleteInput() const {
  throw std::logic_error("Incomplete input");
}
