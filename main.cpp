#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main () {

  assert (strcmp ("Moloko vkusnoe", translit((const unsigned char *) "Молоко вкусное")) == 0);


  return 0;

}
