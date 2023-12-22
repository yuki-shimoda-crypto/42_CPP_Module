// #include "iter.hpp"
// template <class T> void printFunc(const T &element) {
//   std::cout << element << std::endl;
// }
// 
// int main(void) {
//   {
//     int array[5];
// 
//     for (int i = 0; i < 5; i++) {
//       array[i] = i;
//     }
//     iter(array, 5, printFunc);
//   }
//   {
//     std::string array[5] = {"A", "B", "C", "D", "E"};
//     iter(array, 5, printFunc);
//   }
//   return (0);
// }

// #include "iter.hpp"
// 
// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };
// 
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }
// 
// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }
// 
// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];
// 
//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );
// 
//   return 0;
// }

#include "iter.hpp"

class Awesome {
public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

private:
  int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}

template <typename T> void print(T &x) {
  std::cout << x << std::endl;
  return;
}

// template <typename T> void print(const T &x) {
//   std::cout << x << std::endl;
//   return;
// }

int main() {
  int tab[] = {0, 1, 2, 3, 4};
  Awesome tab2[5];

  iter(tab, 5, print<const int>);
  iter(tab2, 5, print<Awesome>);

  iter(tab, 5, print<int>);
  iter(static_cast<const int *>(tab), 5,
       static_cast<void (*)(const int &)>(print));

  // This pattern is not possible
  //  iter(static_cast<const int *>(tab3), 5,
  //       static_cast<void (*)(int &)>(print));

  return 0;
}
