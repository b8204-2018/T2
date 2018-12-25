#include <iostream>
#include <cstring>
#include "translit.h"
#include <cassert>

int main() {

    assert(strcmp("Translit", translit((const unsigned char *) "Транслит")) == 0);
    assert(strcmp("TrAnSlIt", translit((const unsigned char *) "ТрАнСлИт")) == 0);
    assert(strcmp("TRANSLIT", translit((const unsigned char *) "ТРАНСЛИТ")) == 0);
    assert(strcmp("klyovyj Translit", translit((const unsigned char *) "клёвый Транслит")) == 0);
    assert(strcmp("Jo ho ho", translit((const unsigned char *) "Йо хо хо")) == 0);
    assert(strcmp("!!!T!!!", translit((const unsigned char *) "!!!Т!!!")) == 0);
    assert(strcmp("Shchyochki", translit((const unsigned char *) "Щёчки")) == 0);
    return 0;
}