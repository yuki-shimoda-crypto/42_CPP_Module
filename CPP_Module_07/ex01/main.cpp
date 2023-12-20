#include "iter.hpp"

template <class T> void printFunc(const T &element) {
  std::cout << element << std::endl;
}

int main(void) {
  {
    int array[5];

    for (int i = 0; i < 5; i++) {
      array[i] = i;
    }
    iter(array, 5, printFunc);
  }
  {
    std::string array[5] = {"A", "B", "C", "D", "E"};
    iter(array, 5, printFunc);
  }
  return (0);
}
