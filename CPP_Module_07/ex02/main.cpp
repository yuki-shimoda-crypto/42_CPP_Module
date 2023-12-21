#include "Array.hpp"

int main(void) {
  {
    Array<int> arrayA(0);
    Array<int> arrayB;

    try {
      std::cout << arrayA.getArray(0) << std::endl;
      std::cout << arrayB.getArray(0) << std::endl;
    } catch (const std::out_of_range &e) {
      std::cerr << e.what() << std::endl;
    }
    try {
      std::cout << arrayB.getArray(0) << std::endl;
    } catch (const std::out_of_range &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    int n = 10;
    Array<int> arrayA(n);
    Array<int> arrayB = arrayA;
    Array<int> arrayC;
    arrayC = arrayA;

    for (int i = 0; i < n; i++) {
      arrayA.setArray(i, i);
      arrayB.setArray(i + n, i);
      arrayC.setArray(i + n * 2, i);
    }
    std::cout << "array size: " << arrayA.size() << std::endl;
    try {
      std::cout << std::setw(10) << "Array A|" << std::setw(10) << "Array B|"
                << std::setw(10) << "Array C|" << std::endl;
      for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << arrayA.getArray(i) << std::setw(10)
                  << arrayB.getArray(i) << std::setw(10) << arrayC.getArray(i)
                  << std::endl;
      }
    } catch (const std::out_of_range &e) {
      std::cerr << e.what() << std::endl;
    }
    try {
      std::cout << arrayA[0] << std::endl;
      std::cout << arrayA[100] << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    return (0);
  }
}
