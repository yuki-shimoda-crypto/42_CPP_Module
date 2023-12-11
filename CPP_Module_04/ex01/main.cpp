#include "Cat.hpp"
#include "Dog.hpp"

static void testDeepCopy() {
  Cat originalCat;
  Cat copiedCat = originalCat;

  std::cout << "Testing deep copy for Cat class:" << std::endl;

  if ((originalCat.getBrain()) != (copiedCat.getBrain())) {
    std::cout << "Deep copy confirmed: Original and copied Cats have different "
                 "Brain addresses."
              << std::endl;
  } else {
    std::cout << "Shallow copy detected: Original and copied Cats have the "
                 "same Brain addresses."
              << std::endl;
  }
}

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
    std::cout << "-------------------------" << std::endl;
    testDeepCopy();
  }
  return (0);
}
