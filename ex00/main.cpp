#include <iostream>

#include "whatever.hpp"

namespace {
void DivTest() {
  std::string n;
  std::cout << "** Pleas Press Enter to do Next Test! **" << std::endl;
  std::getline(std::cin, n);
}

}  // namespace

int main(void) {
  std::cout << "[Test in Subject]" << '\n';
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  DivTest();

  std::cout << "[min Test]" << '\n';
  int a1 = 1;
  int b1 = 1;
  std::cout << "address of a1 : " << &a1 << std::endl;
  std::cout << "address of b1 : " << &b1 << std::endl;
  int& c1 = min(a1, b1);
  std::cout << "address of min( a1, b1 ) : " << &c1 << std::endl;

  DivTest();

  std::cout << "[max Test]" << '\n';
  int a2 = 1;
  int b2 = 1;
  std::cout << "address of a2 : " << &a2 << std::endl;
  std::cout << "address of b2 : " << &b2 << std::endl;
  int& c2 = max(a2, b2);
  std::cout << "address of max( a2, b2 ) : " << &c2 << std::endl;

  return 0;
}
