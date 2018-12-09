#include <iostream>
#include "translit.h"
#include <cstring>

char *translit(const unsigned char *s) {
    const char alph[][4] = { "a", "b", "v", "g", "d", "e",
                             "zh", "z", "i", "j", "k", "l",
                             "m", "n", "o", "p", "r", "s",
                             "t", "u", "f", "h", "c", "ch",
                             "sh", "sch", "", "y", "", "eh",
                             "ju", "ja"};
    std::string result ("");
    int i=0;
        while ((int*)s[i] != 0)
    {
        if ((s[i] == 0xd0) || (s[i] == 0xd1)) {
            if (s[i] == 0xd0) {
                i++;
                result = result + alph[(int) s[i] - 176];
            } else {
                i++;
                result = result + alph[(int) s[i] - 112];
            }
        } else {
            char unnamed = s[i];
            result = result + unnamed;
        }
        i++;
    }
    std::cout << result << std::endl;
    char res[i+1];
    strcpy(res, result.c_str());
    return res;
}
