#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>    
using namespace std;
//																				B=0xd0 0x91 П = 0xd0 0x9f
int main() {
	assert(strcmp("PRIVET", translit((const unsigned char *) "ПРИВЕТ")) == 0);
	system("pause");
    return 0;

}
