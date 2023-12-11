#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &wrong_animal);
  WrongAnimal &operator=(const WrongAnimal &wrong_animal);
  virtual ~WrongAnimal();
  void makeSound() const;
  std::string getType() const;

protected:
  std::string _type;
};

#endif
