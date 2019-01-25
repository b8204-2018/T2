#include <iostream>
#include <cstring>
#include <cassert>

#include "src/translit.h"
#include "src/translit.cpp"

int main () {
assert (strcmp ("Moloko vkusnoe", translit((const unsigned char *) "Молоко вкусное")) == 0);

std::cout << "\n\nВыполняем транслит\n\n";
std::cout << translit((const unsigned char *) "Молоко вкусное") << std::endl;

  return 0;

}
