#include "src/translit.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  assert(strcmp("SPASIISOHRANI",translit((const unsigned char *)"СПАСИИСОХРАНИ")) == 0);
  return 0;
}
