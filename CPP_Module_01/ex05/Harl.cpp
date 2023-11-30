#include "Harl.hpp"

void Harl::complain(const std::string &level) const {
  int index = 0;
  void (Harl::*func_ptr[])(void) const = {
      &Harl::invalid, &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

  index += (level == "DEBUG") * 1 + (level == "INFO") * 2 +
           (level == "WARNING") * 3 + (level == "ERROR") * 4;
  (this->*func_ptr[index])();
}

void Harl::invalid(void) const { std::cout << "Invalid level" << std::endl; }

void Harl::debug(void) const {
  std::cout
      << " love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) const {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) const {
  std::cout
      << " think I deserve to have some extra bacon for free. I’ve been coming "
         "for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error(void) const {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

