#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    assert(strcmp("ELENA", translit((const unsigned char *) "ЕЛЕНА")) == 0);
    assert(strcmp("Matematika", translit((const unsigned char *) "Математика")) == 0);
    assert(strcmp("Vosem'", translit((const unsigned char *) "Восемь")) == 0);
    assert(strcmp("Chest'", translit((const unsigned char *) "Шесть")) == 0);
    assert(strcmp("Pervaya para", translit((const unsigned char *) "Первая пара")) == 0);
    return 0;
}