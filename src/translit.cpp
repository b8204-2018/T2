#include "translit.h"
#include <cstring>

char *translit(const unsigned char *s) {
    char letters[64][4] = {"A", "B", "V", "G", "D", "E", "Zh", "Z", "I", "J",  //4 для наибольшей последовательности + конец строки
                           "K", "L", "M", "N", "O", "P", "R", "S", "T", "U",
                           "F", "H", "Ts", "Ch", "Sh", "Sch", "/", "Y", "'", "E",
                           "Yu", "Ya", "a", "b", "v", "g", "d", "e", "zh", "z",
                           "i", "j", "k", "l", "m", "n", "o", "p", "r", "s",
                           "t", "u", "f", "h", "ts", "ch", "sh", "sch", "/", "y", "'", "e", "yu", "ya"};
    int j = 0, length = 0;
    unsigned short int pos = 0;

    for (int i = 0; s[i] != '\0'; i++){
        length++;
    }

    char *str = new char[length * 4];

    for (int i = 0; i < length; i++) {
        if (s[i] == 0xd0 || s[i] == 0xd1) {
            int symbol = (s[i] << 8) + s[i + 1];  // << 8 - сдвигаем на байт + номер(код) символа (всего 2 байта)
            //std::cout << symbol << std::endl;  //53439 - D0BF - п
            if (symbol >= 0xd090 && symbol < 0xd180) { //для 0хd0
                pos = symbol - 0xd090;  //позиция в letters[62][4]
                memcpy(str + j, letters[pos], sizeof(letters[pos]));
                j = j + strlen(letters[pos]);
            }
            if (symbol >= 0xd180 && symbol <= 0xd18f) {  //для 0хd1
                pos = (0xd0bf - 0xd090) + (symbol - 0xd180) + 1;
                memcpy(str + j, letters[pos], sizeof(letters[pos]));
                j = j + strlen(letters[pos]);
            }
            if (symbol == 0xd081) {
                memcpy(str + j, "Yo", strlen("Yo"));
                j = j + strlen("Yo");
            } else if (symbol == 0xd191) {
                memcpy(str + j, "yo", strlen("yo"));
                j = j + strlen("yo");
            }
            i++;
        } else {
            memcpy(str + j, s + i, 1);
            j++;
        }
    }
    str[j] = '\0';
    return str;
}
