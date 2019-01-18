#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"
using namespace std;

int main() {
    assert(strcmp("son", translit((const unsigned char *) "сон")) == 0);
    assert(strcmp("MOROZhENOE", translit((const unsigned char *) "МОРОЖЕНОЕ")) == 0);
    assert(strcmp(".-.", translit((const unsigned char *) ".-.")) == 0);
    assert(strcmp("Motylyok", translit((const unsigned char *) "Мотылёк")) == 0);
    assert(strcmp("Tsennost'", translit((const unsigned char *) "Ценность")) == 0);
    assert(strcmp("Schast'e", translit((const unsigned char *) "Счастье")) == 0);
    assert(strcmp("Lampa", translit((const unsigned char *) "Лампа"))  == 0);
    assert(strcmp("Schenok", translit((const unsigned char *) "Щенок")) == 0);
    return 0;
}