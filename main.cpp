#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>


int main() {
 assert(strcmp("PRIVET", translit((const unsigned char *) "ПРИВЕТ")) == 0);
    assert(strcmp("KRASOTISHYA", translit((const unsigned char *) "КРАСОТИЩА")) == 0);
    assert(strcmp("SNOVYMGODOM", translit((const unsigned char *) "С НОВЫМ ГОДОМ")) == 0);
    return 0;
}
