#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("poka", translit((const unsigned char *) "пока")) == 0);
    assert(strcmp("VIKA", translit((const unsigned char *) "ВИКА")) == 0);
    assert(strcmp("Cherv'", translit((const unsigned char *) "Червь")) == 0);
    assert(strcmp("Mama", translit((const unsigned char *) "Мама")) == 0);
    assert(strcmp("Sem'", translit((const unsigned char *) "Семь")) == 0);
    assert(strcmp("Poezd", translit((const unsigned char *) "Поезд")) == 0);
    assert(strcmp("Vyhod", translit((const unsigned char *) "Выход")) == 0);
    assert(strcmp("Aloe", translit((const unsigned char *) "Алоэ")) == 0);
    return 0;
}