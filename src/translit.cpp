//
// Created by DELL on 25.12.2018.
//

#include "translit.h"
#include <cstring>

char *translit(const unsigned char *s) {
    char rusAlph[][5] = {"A", "B", "V", "G", "D", "E", "Zh", "Z", "I", "J",
                         "K", "L", "M", "N", "O", "P", "R", "S", "T", "U",
                         "F", "H", "Ts", "Ch", "Sh", "Shch", "", "Y", "'", "E",
                         "Yu", "Ya", "a", "b", "v", "g", "d", "e", "zh", "z",
                         "i", "j", "k", "l", "m", "n", "o", "p", "r", "s",
                         "t", "u", "f", "h", "ts", "ch", "sh", "shch", "", "y",
                         "'", "e", "yu", "ya"};

    int leng = 0, pos, code, j=0;
    for (int i = 0; s[i] != '\0'; i++) { leng++; }

    char *engS = new char[leng * 5];

    for (int i = 0; i < leng; i++) {
        if (s[i] == 0xd0 || s[i] == 0xd1) {
            code = (s[i] << 8) + s[i + 1];
            if (code >= 0xd090 && code < 0xd180) {
                pos = code - 0xd090;
                memcpy(engS + j, rusAlph[pos], strlen(rusAlph[pos]));
                j = j + strlen(rusAlph[pos]);
            }
            if (code >= 0xd180 && code <= 0xd18f) {
                pos = (0xd0bf - 0xd090) + (code - 0xd180) + 1;
                memcpy(engS + j, rusAlph[pos], strlen(rusAlph[pos]));
                j = j + strlen(rusAlph[pos]);
            }
            if (code == 0xd081) {
                memcpy(engS + j, "Yo", strlen("Yo"));
                j = j + strlen("Yo");
            } else if (code == 0xd191) {
                memcpy(engS + j, "yo", strlen("YO"));
                j = j + strlen("yo");
            }
            i++;
        } else {
            memcpy(engS + j, s + i, 1);
            j++;
        }
    }
    engS[j] = '\0';
    return engS;
}