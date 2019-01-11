#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    assert(strcmp("TRANSLIT", translit((const unsigned char *) "ТРАНСЛИТ")) == 0);
    assert(strcmp("yozhik", translit((const unsigned char *) "ёжик")) == 0);
    assert(strcmp("Zaveschanie", translit((const unsigned char *) "Завещание")) == 0);
    assert(strcmp("Vosem'", translit((const unsigned char *) "Восемь")) == 0);
    assert(strcmp("Ob/Yom", translit((const unsigned char *) "ОбъЁм")) == 0);
    assert(strcmp("Ssylka", translit((const unsigned char *) "Ссылка")) == 0);
    assert(strcmp(":-)", translit((const unsigned char *) ":-)")) == 0);
    assert(strcmp("Aloe", translit((const unsigned char *) "Алоэ")) == 0);
    return 0;
}