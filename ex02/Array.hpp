#ifndef Array_HPP
#define Array_HPP
#include <stdexcept>

template <typename T>
class Array {
 private:
  T*           arr_;
  unsigned int size_;

 public:
  ~Array();
  Array();
  Array(unsigned int n);
  Array(const Array& arr);
  Array&       operator=(const Array& arr);
  T&           operator[](int index) const;
  unsigned int Size() const;
};

#include "Array.tpp"

#endif