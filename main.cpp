#include <iostream>
#include <cstring>
#include "src/translit.h"
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    assert(strcmp("DROU", translit((const unsigned char *) "ДРОУ")) == 0);
    assert(strcmp("YA pOvAr", translit((const unsigned char *) "Я пОвАр")) == 0);
    assert(strcmp("SCHavel\'", translit((const unsigned char *) "Щавель")) == 0);
    assert(strcmp("SHishka", translit((const unsigned char *) "Шишка")) == 0);
    return 0;
}
