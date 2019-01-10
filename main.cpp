#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    assert(strcmp(translit((const unsigned char *) "Шалашаска"), "Shalashaska") == 0);
    assert(strcmp(translit((const unsigned char *) "Йорвет"), "Jorvet") == 0);
    assert(strcmp(translit((const unsigned char *) "123"), "123") == 0);
    assert(strcmp(translit((const unsigned char *) "Щас-через час"), "Schas-cherez chas") == 0);
    assert(strcmp(translit((const unsigned char *) "ВиТаМиНкА"), "ViTaMiNkA") == 0);
    assert(strcmp(translit((const unsigned char *) "ёёёжиииик!"), "yoyoyozhiiiik!") == 0);
    return 0;
}