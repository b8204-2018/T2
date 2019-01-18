#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    assert(strcmp("KIRILL", translit((const unsigned char *) "КИРИЛЛ")) == 0);
    assert(strcmp("MOHOVIChENKO", translit((const unsigned char *) "МОХОВИЧЕНКО")) == 0);
    assert(strcmp("Dom", translit((const unsigned char *) "Дом")) == 0);
    assert(strcmp("Vosem'", translit((const unsigned char *) "Восемь")) == 0);
    assert(strcmp("Poezd", translit((const unsigned char *) "Поезд")) == 0);
    assert(strcmp("Ssylka", translit((const unsigned char *) "Ссылка")) == 0);
    assert(strcmp("Aloe", translit((const unsigned char *) "Алоэ")) == 0);
    return 0;
}