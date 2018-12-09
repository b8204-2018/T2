#include <iostream>
#include <cstring>
#include "src/translit.h"

int main() {
    // use only small letters please
    std::cout << translit((const unsigned char *) "здарова бандиты!") << std::endl;

    return 0;
}
