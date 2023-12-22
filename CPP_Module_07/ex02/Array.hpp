#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iomanip>
#include <iostream>

template <class T> class Array {
public:
  Array();
  Array(unsigned int n);
  Array(const Array &array);
  Array &operator=(const Array &array);
  ~Array();

  T &operator[](std::size_t pos);
  const T &operator[](std::size_t pos) const;
  std::size_t size() const;

  //   debug
  //   const T &getArray(std::size_t n) const;
  //   void setArray(const T &array, std::size_t n);

private:
  T *_array;
  std::size_t _arraySize;
};

template <class T> Array<T>::Array() : _array(NULL), _arraySize(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _arraySize(n) {}

template <class T>
Array<T>::Array(const Array &array)
    : _array(new T[array._arraySize]), _arraySize(array._arraySize) {
  for (std::size_t i = 0; i < array._arraySize; i++) {
    this->_array[i] = array._array[i];
  }
}

template <class T> Array<T> &Array<T>::operator=(const Array &array) {
  if (this != &array) {
    delete[] this->_array;
    this->_array = new T[array._arraySize];
    this->_arraySize = array._arraySize;
    for (std::size_t i = 0; i < array._arraySize; i++) {
      this->_array[i] = array._array[i];
    }
  }
  return (*this);
}

template <class T> Array<T>::~Array() { delete[] this->_array; }

template <class T> T &Array<T>::operator[](std::size_t pos) {
  if (pos < this->_arraySize) {
    return (this->_array[pos]);
  } else {
    throw std::out_of_range("Index out of range");
  }
}

template <class T> const T &Array<T>::operator[](std::size_t pos) const {
  if (pos < this->_arraySize) {
    return (this->_array[pos]);
  } else {
    throw std::out_of_range("Index out of range");
  }
}

template <class T> std::size_t Array<T>::size() const {
  return (this->_arraySize);
}

// debug
// template <class T> const T &Array<T>::getArray(std::size_t n) const {
//   if (n < this->_arraySize) {
//     return (_array[n]);
//   } else {
//     throw std::out_of_range("Index out of range");
//   }
// }
//
// template <class T> void Array<T>::setArray(const T &array, std::size_t n) {
//   this->_array[n] = array;
// }

#endif
