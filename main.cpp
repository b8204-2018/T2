#include <iostream>
#include "translit.h"
#include "assert.h"
#include "cstring"

int main() {
    assert(strcmp("RAZNOE", translit((const unsigned char *) "РАЗНОЕ")) == 0);
    return 0;
}