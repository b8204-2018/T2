#include <cstring>
#include "translit.h"

char *translit(const unsigned char *s) {
    char eng [][4] = {
            "A", "B", "V", "G", "D", "E", "ZH", "Z", "I", "Y", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F",
            "H", "TS", "CH", "SH", "SCH", "", "I", "\'", "E", "YU", "YA",
            "a", "b", "v", "g", "d", "e", "zh", "z", "i", "y", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f",
            "h", "ts", "ch", "sh", "sch", "", "i", "\'", "e", "yu", "ya"
    };
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++, len++);
    char *trStr = new char[len * 4];
    int  j = 0, pos;
    for (int i = 0; i < len; i++) {
        if (s[i] == 0xd0 || s[i] == 0xd1){
            pos = (s[i] << 8) + s[i + 1];
            if (pos >= 0xd090 && pos < 0xd180){
                pos -= 0xd090;
                memcpy(trStr + j, eng[pos], strlen(eng[pos]));
                j += strlen(eng[pos]);
            }
            if (pos >= 0xd180 && pos <=0xd18f){
                pos = (0xd0bf - 0xd090 + 1) + (pos - 0xd180);
                memcpy(trStr + j, eng[pos], strlen(eng[pos]));
                j += strlen(eng[pos]);
            }
            if (pos == 0xd081) {
                memcpy(trStr + j, "YO", strlen("YO"));
                j += strlen("YO");
            }
            else if (pos == 0xd191){
                memcpy(trStr + j, "yo", strlen("YO"));
                j += strlen("yo");
            }
            i++;
        }
        else{
            memcpy(trStr + j, s + i, 1);
            j++;
        }
    }
    trStr[j] = '\0';
    return trStr;
}
