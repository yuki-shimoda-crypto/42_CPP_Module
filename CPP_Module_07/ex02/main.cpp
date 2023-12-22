#include "Array.hpp"

void print(Array<int> &array) {
  array[0] = 0;
  std::cout << array[0] << std::endl;
}

void printConst(const Array<int> &array) {
  // array[0] = 0;
  std::cout << array[0] << std::endl;
}

int main(void) {
  {
    int n = 10;
    Array<int> arrayA(n);
    Array<int> arrayB(n);

    arrayA[0] = 1;
    arrayB[0] = 1;
    print(arrayA);
    printConst(arrayB);
    return (0);
  }
}

// #include <iostream>
// //#include <Array.hpp>
// #include "Array.hpp"
// #include <cstdlib>
// 
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
// 
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// 
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
