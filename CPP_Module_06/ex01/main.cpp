#include "Serializer.hpp"

int main(void) {
  Serializer serializer;
  Data data;

  std::cout << &data << std::endl;
  std::cout << serializer.deserialize(serializer.serialize(&data)) << std::endl;
  return (0);
}
