#include <iostream>
#include <cstring>
#include "translit.h"

char Angl [][4] = {
            "A", "B", "V", "G", "D", "E", "ZH", "Z", "I", "Y", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F", "H", "TS", "CH", "SH", "SCH", "", "I", "", "E", "YU", "YA", 
            "a", "b", "v", "g", "d", "e", "zh", "z", "i", "y", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f", "h", "ts", "ch", "sh", "sch", "", "i", "", "e", "yu", "ya"
    };

char *translit(const unsigned char *s) {

int dlina = 0;
int i = 0;
int  j = 0;
int posit;
for (i = 0; s[i] != '\0'; i++, dlina++);
char *res = new char[dlina*4];

for (i = 0; i < dlina; i++) {
  if (s[i] == 0xd0 || s[i] == 0xd1) {
      posit = (s[i] << 8) + s[i + 1];
      if (posit >= 0xd090 && posit < 0xd180) {
          posit = posit - 0xd090;
          memcpy(res + j, Angl[posit], strlen(Angl[posit]));
          j = j + strlen(Angl[posit]);
      } if (posit >= 0xd180 && posit <=0xd18f) {
          posit = (0xd0bf - 0xd090 + 1) + (posit - 0xd180);
          memcpy(res + j, Angl[posit], strlen(Angl[posit]));
          j = j + strlen(Angl[posit]);
      } if (posit == 0xd081) {
          memcpy(res + j, "YO", strlen("YO"));
          j = j + strlen("YO");
      } else if (posit == 0xd191) {
          memcpy(res + j, "yo", strlen("YO"));
          j = j + strlen("yo");
      } i++;
  } else {
      memcpy(res + j, s + i, 1);
      j++;
  }
} res[j] = '\0';

return res;

}
