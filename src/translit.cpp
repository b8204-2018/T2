#include "translit.h"
#include <cstring>

char *translit(const unsigned char *s) {
    const unsigned char rus[][3] = {"А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К",
                                    "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х",
                                    "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я",
                                    "а", "б", "в", "г", "д", "е", "ж", "з", "и","й", "к", "л",
                                    "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц",
                                    "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};


    const char eng[][5] = {"A", "B", "V", "G", "D", "E", "Zh", "Z", "I", "J", "K",
                           "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "H",
                           "Ts", "Ch", "Sh", "Shch", "", "Y", "'", "E", "Yu", "Ya",
                           "a", "b", "v", "g", "d", "e", "zh", "z", "i", "j", "k",
                           "l", "m", "n", "o", "p", "r", "s", "t", "u", "f", "h",
                           "ts","ch", "sh", "shch", "", "y", "'", "e", "yu", "ya"};

    int length = 0;
    for (int i = 0; s[i] != '\0'; i++){
        length = length + 1;
    }

    char *output = new char [length * 5];
    int i = 0;
    int j = 0;
    short pos;
    unsigned char *letter = new unsigned char [3];
    while (i < length) {
        if ((s[i] == 0xd0 && s[i + 1] >= 0x90 && s[i + 1] <= 0xbf) || (s[i] == 0xd1 && s[i + 1] >= 0x80 && s[i + 1] <= 0x8f)){
            letter[0] = s[i];
            letter[1] = s[i + 1];
            letter[2] = '\0';
            for (pos = 0; strcmp((const char*)rus[pos], (const char*)letter) != 0; pos++);
            memcpy(output + j, eng[pos], strlen(eng[pos]));
            j += strlen(eng[pos]);
            i += 2;
        } else if (s[i] == 0xd0 && s[i + 1] == 0x81){
            memcpy(output + j, "Yo", strlen("Yo"));
            j += strlen("Yo");
            i += 2;
        } else if (s[i] == 0xd1 && s[i + 1] == 0x91){
            memcpy(output + j, "yo", strlen("yo"));
            j += strlen("yo");
            i += 2;
        } else {
            memcpy(output + j, s + i, 1);
            j++;
            i++;
        }
    }
    output[j] = '\0';
    return output;
};