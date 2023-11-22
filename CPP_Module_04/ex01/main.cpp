#include "Dog.hpp"
#include "Cat.hpp"

int main() {
  {
    const Animal *animals[4];

    for (int i = 0; i < 4; i++) {
      if (i < 2) {
        animals[i] = new Dog;
      } else {
        animals[i] = new Cat;
      }
    }
    for (int i = 0; i < 4; i++) {
      delete animals[i];
    }
  }
  {
    Dog dog1;
    Dog dog2 = dog1;
    Dog dog3;

    dog3 = dog1;
    std::cout << std::endl;
  }
  return 0;
}
