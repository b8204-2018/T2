#include "translit.h"
#include <cstring>


char *translit(const unsigned char *s) {
    char alphabet [][5] = {"A", "B", "V", "G", "D", "E", "Zh", "Z", "I", "J", "K",
                    "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "H",
                    "Ts", "Ch", "Sh", "Shch", "", "Y", "'", "E", "Yu", "Ya",
                    "a", "b", "v", "g", "d", "e", "zh", "z", "i", "j", "k", "l",
                    "m", "n", "o", "p", "r", "s", "t", "u", "f", "h", "ts",
                    "ch", "sh", "shch", "", "y", "'", "e", "yu", "ya"};

    int length = 0;
    for (int i = 0; s[i] != '\0'; i++){
        length = length + 1;
    }
    char *output = new char [length*5];
    int i = 0;
    int j = 0;
    int pos;
    while (i < length) {
        if (s[i] == 0xd0 || s[i] == 0xd1){
            pos  = (s[i] << 8) + s[i+1];
            if (pos >= 0xd090 && pos <= 0xd18f ) {
                if (pos>=0xd090 && pos < 0xd180) {
                    pos = pos - 0xd090;
                } else if (pos >= 0xd180 && pos <=0xd18f){
                    pos = ( pos - 0xd180) + (0xd0bf - 0xd090) + 1;
                }
                memcpy(output + j, alphabet[pos], strlen(alphabet[pos]));
                j = j + strlen(alphabet[pos]);
            }
            if (pos == 0xd081) {
                memcpy(output + j, "Yo", strlen("Yo"));
                j = j + strlen("Yo");
            }
            if (pos == 0xd191) {
                memcpy(output + j, "yo", strlen("yo"));
                j = j + strlen("yo");
            }
            i = i + 2;
        } else {
            memcpy(output + j, s + i, 1);
            j = j + 1;
            i = i + 1;
        }
    }
    output[j] = '\0';
    return output;
};