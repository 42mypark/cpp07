#ifndef Array_HPP
#define Array_HPP
#include <exception>
template <typename T>
class Array {
 private:
  T*           arr_;
  unsigned int size_;

 public:
  ~Array() {
    delete[] arr_;
  }
  Array() : arr_(0), size_(0) {
  }
  Array(unsigned int n) : arr_(0) {
    size_ = n;
    arr_ = new T[n];
  }
  Array(const Array& arr) : arr_(0), size_(0) {
    *this = arr;
  }
  Array& operator=(const Array& arr) {
    size_ = arr.Size();
    arr_ = new T[size_];
    for (unsigned int i = 0; i < size_; i++)
      arr_[i] = arr[i];
    return *this;
  }
  T& operator[](int index) const {
    if (static_cast<unsigned int>(index) >= size_)
      throw std::out_of_range("index out of range");
    return arr_[index];
  }
  unsigned int Size() const {
    return size_;
  }
};

#endif  // Array_HPP
