#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    std:: cout << translit((const unsigned char *) "привет") << '\n';
    std:: cout << translit((const unsigned char *) "Как дела?");
    //assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    return 0;
}
