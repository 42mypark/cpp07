#include <cstdlib>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

namespace {

void DivTest() {
  std::string n;
  std::cout << "** Pleas Press Enter to do Next Test! **" << std::endl;
  std::getline(std::cin, n);
}

void MyTest() {
  std::cout << "[default constructor]" << std::endl;
  {
    Array<int> a;
    std::cout << a.Size() << '\n';
  }
  std::cout << '\n';
  std::cout << "[copy constructor & operator=]" << std::endl;
  {
    Array<int> a(10);
    for (unsigned int i = 0; i < a.Size(); i++)
      a[i] = rand();
    Array<int> b(a);
    b[10 - 1] = -1;
    for (unsigned int i = 0; i < a.Size(); i++) {
      std::cout << "a[" << i << "] = " << a[i] << "\t\t";
      std::cout << "b[" << i << "] = " << b[i] << '\n';
    }
  }
  std::cout << std::endl;
  DivTest();
  std::cout << "[operator[] index out of range]" << std::endl;
  {
    Array<int> a(10);
    for (unsigned int i = 0; i < a.Size(); i++)
      a[i] = rand();
    try {
      a[-1] = 1;
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    try {
      a[20] = 1;
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
  std::cout << std::endl;
}
}  // namespace

int main(int, char**) {
  Array<int> numbers(MAX_VAL);
  int*       mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;  //

  DivTest();

  MyTest();
  return 0;
}
