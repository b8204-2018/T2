#include <iostream>
#include <string.h>

using namespace std;

char *translit(const unsigned char *data) {
  const char alf[][4] = {"A",  "B",   "V", "G", "D", "E",  "ZH", "Z",
                         "I",  "J",   "K", "L", "M", "N",  "O",  "P",
                         "R",  "S",   "T", "U", "F", "H",  "C",  "CH",
                         "SH", "SCH", "",  "Y", "",  "EH", "JU", "JA"};
  int len = 0;
  while (data[len] != 0) {
    len++;
  }
  char *res = new char[len / 2]; //результирующий массив символов
  int position = 0;              //позиция в alf
  int j = 0;                     //счётчик сдвига байтов

  for (int i = 0; i <= len; i++) {
    if (data[i] >= 0xd0 && data[i] <= 0xd1) {
      position = data[i + 1] - 0x90;
      memcpy(res + j, alf[position], strlen((alf[position])));
      j = j + strlen(alf[position]);
      i++;
    } else if (data[i] == ' ') {
      res[j] = ' ';
      j++;
    }
  }
  return res;
}
