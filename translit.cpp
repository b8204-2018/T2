#include <iostream>
#include <locale>
#include <cstring>
#include "assert.h"

using namespace std;

typedef unsigned char UCHAR;

const size_t C_SIZE = 4;

//Транслитный русский алфавит на английском
const UCHAR Angl[][C_SIZE] = {
        "A", "B", "V", "G", "D", "E", "ZH", "Z", "I", "Y", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "H",
        "C", "CH", "SH", "SCH", "Y", "IY", "", "IE", "YU", "YA"
};

int translit() {
    UCHAR s[] = "МОЛОКО ВКУСНОЕ"; //Строка, которую необходимо транслитнуть
    for (size_t i = 0, len = sizeof(s); i < len; i++) {
        UCHAR smv[C_SIZE];
        if (s[i] == 0xd0 || s[i] == 0xd1) {
            unsigned short int posit(0);
            memmove(&posit, s+i, 2 * sizeof(UCHAR));
            posit = posit - (unsigned short int) 0x90d0;
            posit = posit % 255;
            memmove(smv, (void*)Angl[posit], C_SIZE * sizeof(UCHAR));
            i++;
        } else {
            memmove(smv, s+i, sizeof(UCHAR));
        }
        cout << smv;
    }
    return 0;
}