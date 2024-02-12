#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

class RpnCalculator {
public:
  RpnCalculator();
  RpnCalculator(const RpnCalculator &rpnCalculator);
  RpnCalculator &operator=(const RpnCalculator &);
  ~RpnCalculator();

  double evaluate(const std::string &input);

  void applyOperator(const char op);

private:
  std::stack<double> _stack;

  // Util
  bool isOperator(const char ch) const;
  bool isSpace(const char ch) const;

  // Error Handle
  void handleEmptyStack() const;
  void handleDivisionByZero() const;
  void handleInvalidInput(const char ch) const;
  void handleIncompleteInput() const;
};

#endif
