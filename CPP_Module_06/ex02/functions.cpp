#include "functions.hpp"

Base *generate(void) {
  std::srand(std::time(0));
  if (std::rand() % 3 == 0) {
    std::cout << "return A" << std::endl;
    return (new A);
  } else if (std::rand() % 3 == 1) {
    std::cout << "return B" << std::endl;
    return (new B);
  } else {
    std::cout << "return C" << std::endl;
    return (new C);
  }
  return (NULL);
}

void identify(Base *p) {
  std::cout << "identify(Base *p)" << std::endl;
  if (dynamic_cast<A *>(p)) {
    std::cout << "The actual type of the object pointed to by p: A"
              << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "The actual type of the object pointed to by p: B"
              << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "The actual type of the object pointed to by p: C"
              << std::endl;
  } else {
    std::cout << "Invalid type" << std::endl;
  }
}

void identify(Base &p) {
  std::cout << "identify(Base &p)" << std::endl;
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "The actual type of the object pointed to by p: A"
              << std::endl;
  } catch (const std::exception &e) {
    try {
      B &b = dynamic_cast<B &>(p);
    (void)b;
      std::cout << "The actual type of the object pointed to by p: B"
                << std::endl;
    } catch (const std::exception &e) {
      try {
        C &c = dynamic_cast<C &>(p);
    (void)c;
        std::cout << "The actual type of the object pointed to by p: C"
                  << std::endl;
      } catch (const std::exception &e) {
        std::cout << "Invalid type" << std::endl;
      }
    }
  }
}
