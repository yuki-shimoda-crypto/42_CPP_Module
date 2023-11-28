#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }
int Account::getTotalAmount(void) { return (Account::_totalAmount); }
int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }
void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";"
            << "total:" << Account::getTotalAmount() << ";"
            << "deposits:" << Account::getNbDeposits() << ";"
            << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(this->_nbAccounts), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0) {
  this->_nbAccounts += 1;
  this->_totalAmount += this->_amount;
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "created" << std::endl;
}

Account::~Account(void) {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  int p_amount = this->_amount;

  this->_totalAmount += deposit;
  this->_totalNbDeposits += 1;
  this->_amount += deposit;
  this->_nbDeposits += 1;
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << p_amount << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << this->_amount << ";"
            << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  int p_amount = this->_amount;

  this->_displayTimestamp();
  if (p_amount < withdrawal) {
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << p_amount << ";"
              << "withdrawal:"
              << "refused" << std::endl;
    return (false);
  }
  this->_totalAmount -= withdrawal;
  this->_totalNbWithdrawals += 1;
  this->_amount -= withdrawal;
  this->_nbWithdrawals += 1;
  std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << p_amount << ";"
            << "withdrawal:" << withdrawal << ";"
            << "amount:" << this->_amount << ";"
            << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus(void) const {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "deposits:" << this->_nbDeposits << ";"
            << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  time_t time = std::time(NULL);
  struct tm *timeinfo = localtime(&time);

  std::cout << "[" << timeinfo->tm_year + 1900 << std::setw(2)
            << std::setfill('0') << timeinfo->tm_mon << std::setw(2)
            << std::setfill('0') << timeinfo->tm_mday << "_" << std::setw(2)
            << std::setfill('0') << timeinfo->tm_hour << std::setw(2)
            << std::setfill('0') << timeinfo->tm_min << std::setw(2)
            << std::setfill('0') << timeinfo->tm_sec << "] ";
}
