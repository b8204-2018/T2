#include "src/translit.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  assert(strcmp("HVATIT",translit((const unsigned char *)"ХВАТИТ")) == 0);
  return 0;
}
