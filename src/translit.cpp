#include "translit.h"
#include <cstring>

char *translit(const unsigned char *s) {
    char alpha [][4] = {"A", "B", "V", "G", "D", "E", "Zh", "Z", "I", "J",  //если я выделю 4 эллемента, оно должно заработать, потому что нельзя забывать про конец строки
                        "K", "L", "M", "N", "O", "P", "R", "S", "T", "U",
                        "F", "H", "Ts", "Ch", "Sh", "Sch", "/", "Y", "'", "E",
                        "Yu", "Ya",
                        "a", "b", "v", "g", "d", "e", "zh", "z", "i", "j",
                        "k", "l", "m", "n", "o", "p", "r", "s", "t", "u",
                        "f", "h", "ts", "ch", "sh", "sch", "/", "y", "'", "e",
                        "yu", "ya"};
    int lng = 0;
    for (int i = 0; s[i] != '\0'; i++){
        lng++;
    }
    char *out = new char [lng*4];
    int i = 0;
    int j = 0;
    int pos;
    while (i < lng) {
        if (s[i] == 0xd0 || s[i] == 0xd1){
            pos  = (s[i] << 8) + s[i+1];
            if (pos == 0xd191) {
                memcpy(out + j, "yo", strlen("yo"));
                j = j + strlen("yo");
            }
            if (pos == 0xd081) {
                memcpy(out + j, "Yo", strlen("Yo"));
                j = j + strlen("Yo");
            }
            if (pos >= 0xd090 && pos <= 0xd18f ) {
                if (pos>=0xd090 && pos < 0xd180) {
                    pos = pos - 0xd090;
                } else if (pos >= 0xd180 && pos <=0xd18f){
                    pos = ( pos - 0xd180) + (0xd0bf - 0xd090) + 1;
                }
                memcpy(out + j, alpha[pos], strlen(alpha[pos]));
                j = j + strlen(alpha[pos]);
            }
            i = i + 2;
        } else {
            memcpy(out + j, s + i, 1);
            j = j + 1;
            i = i + 1;
        }
    }
    out[j] = '\0';
    return out;
};