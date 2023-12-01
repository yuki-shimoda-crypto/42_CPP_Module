#include "Harl.hpp"

void Harl::complain(const std::string &level) const {
  int i = 0;

  if (level == "DEBUG") {
    i = 0;
  } else if (level == "INFO") {
    i = 1;
  } else if (level == "WARNING") {
    i = 2;
  } else if (level == "ERROR") {
    i = 3;
  } else {
    i = 4;
  }
  switch (i) {
  case 0:
    this->debug();
  case 1:
    this->info();
  case 2:
    this->warning();
  case 3:
    this->error();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
  }
}

void Harl::debug(void) const {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
  std::cout << std::endl;
}

void Harl::info(void) const {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
  std::cout << std::endl;
}

void Harl::warning(void) const {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been coming "
         "for years whereas you started working here since last month."
      << std::endl;
  std::cout << std::endl;
}

void Harl::error(void) const {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
  std::cout << std::endl;
}
