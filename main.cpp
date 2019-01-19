#include "src/translit.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  assert(strcmp("PRIVETTT",translit((const unsigned char *)"ПРИВЕТТТ")) == 0);
  return 0;
}
