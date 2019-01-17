#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
	assert(strcmp("prIIIvet", translit((const unsigned char *) "прИИИвет")) == 0);
	assert(strcmp("privet CHELOVEK", translit((const unsigned char *) "привет ЧЕЛОВЕК")) == 0);
	assert(strcmp("privettt", translit((const unsigned char *) "приветТТТ")) == 0);
	
    return 0;
}
