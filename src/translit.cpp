#include <iostream>
#include <string.h>
using namespace std;
char *transliter(const unsigned char *data, int len) {
  const char alf[][6] = {"A",  "B",   "V", "G", "D", "E",  "ZH", "Z",
                         "I",  "J",   "K", "L", "M", "N",  "O",  "P",
                         "R",  "S",   "T", "U", "F", "H",  "C",  "CH",
                         "SH", "SCH", "",  "Y", "",  "EH", "JU", "JA"};
  char *res = new char[len];
  int position = 0;
  int j = 0;
  for (int i = 0; i <= len; i++) {
    if (data[i] >= 0xd0 && data[i] <= 0xd1) {
      position = data[i + 1] - 0x90;
      memcpy(res + j, alf[position], strlen((alf[position])));
      j = j + strlen(alf[position]);
      i++;
    }
  }
  return res;
}
