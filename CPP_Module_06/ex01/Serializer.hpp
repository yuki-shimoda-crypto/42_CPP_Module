#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>
#include <iostream>

class Serializer {
public:
  Serializer();
  Serializer(const Serializer &serializer);
  Serializer &operator=(const Serializer &serializer);
  ~Serializer();

  uintptr_t serialize(Data *ptr);
  Data *deserialize(uintptr_t raw);

private:
};

#endif
