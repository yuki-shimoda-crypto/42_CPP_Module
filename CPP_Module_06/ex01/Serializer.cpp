#include "Serializer.hpp"

Serializer::Serializer(){};

Serializer::Serializer(const Serializer &serializer) { *this = serializer; }

Serializer &Serializer::operator=(const Serializer &serializer) {
  if (this != &serializer) {
  }
  return (*this);
}

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data *ptr) {
  return (reinterpret_cast<std::uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data *>(raw));
}
