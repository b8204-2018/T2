#include <iostream>
#include <cstring>
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    return 0;
}
