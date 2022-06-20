#include "Array.hpp"

template <class T>
Array<T>::~Array() {
  delete[] arr_;
}

template <class T>
Array<T>::Array() : arr_(0), size_(0) {
}

template <class T>
Array<T>::Array(unsigned int n) : arr_(0) {
  size_ = n;
  arr_ = new T[n];
}

template <class T>
Array<T>::Array(const Array& arr) : arr_(0), size_(0) {
  *this = arr;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& arr) {
  size_ = arr.Size();
  arr_ = new T[size_];
  for (unsigned int i = 0; i < size_; i++)
    arr_[i] = arr[i];
  return *this;
}

template <class T>
T& Array<T>::operator[](int index) const {
  if (static_cast<unsigned int>(index) >= size_)
    throw std::out_of_range("index out of range");
  return arr_[index];
}

template <class T>
unsigned int Array<T>::Size() const {
  return size_;
}