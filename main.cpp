#include <iostream>
#include "translit.h"
#include "assert.h"
#include "cstring"

int main() {
    const unsigned char *s;
    translit(s);
    assert(strcmp("MOLOKO VKUSNOE", translit((const unsigned char *) "МОЛОКО ВКУСНОЕ")) == 0);
    return 0;
}