#include <iostream>

#include "iter.hpp"

namespace {
void DivTest() {
  std::string n;
  std::cout << "** Pleas Press Enter to do Next Test! **" << std::endl;
  std::getline(std::cin, n);
}

void Multiply_4(int& a) {
  a = a * 4;
}

void Divide_2(int& a) {
  a = a / 2;
}

template <typename T>
void print_val(T& a) {
  std::cout << a << '\n';
}

}  // namespace

int main(void) {
  int a[] = {1, 2, 3, 4, 5};

  iter(a, 5, Multiply_4);
  iter(a, 5, print_val);
  std::cout << '\n';

  DivTest();

  iter(a, 4, Divide_2);
  iter(a, 5, print_val);

  DivTest();

  std::string s[] = {"apple", "banana", "I'm fine", "hello world"};
  iter(s, 5, print_val);

  std::cout << std::endl;
}
