#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    assert(strcmp(translit((const unsigned char *) "Витёк"), "Vityok") == 0);
    assert(strcmp(translit((const unsigned char *) "щ"), "shch") == 0);
    assert(strcmp(translit((const unsigned char *) "1"), "1") == 0);
    assert(strcmp(translit((const unsigned char *) "ЙогуРТ"), "JoguRT") == 0);
    return 0;
}
