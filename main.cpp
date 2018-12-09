#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    // use only small letters please
    std::cout << translit((const unsigned char*)"привет, как дела?") << std::endl;

    // assert rugaet'sa pomogite
    //assert(((char*)"privet, kak dela?") == (translit((const unsigned char*)"привет, как дела?")));
    return 0;
}
