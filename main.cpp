#include <iostream>
#include "translit.h"
#include "assert.h"
#include "cstring"

int main() {
    assert(strcmp("MOLOKO", translit((const unsigned char *) "МОЛОКО")) == 0);
    return 0;
}