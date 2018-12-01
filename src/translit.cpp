#include <string.h>
using namespace std;
unsigned char *transliter(const unsigned char *data, int len) {
  const unsigned char alf[][6] = {"A",  "B",   "V", "G", "D", "E",  "ZH", "Z",
                                  "I",  "J",   "K", "L", "M", "N",  "O",  "P",
                                  "R",  "S",   "T", "U", "F", "H",  "C",  "CH",
                                  "SH", "SCH", "",  "Y", "",  "EH", "JU", "JA"};
  unsigned char *res = new unsigned char[len / 2];
  int position = 0;
  for (int i = 0; i <= len; i++) {
    if (data[i] >= 0xd0 && data[i] <= 0xd1) {
      position = data[i + 1] - 0x90;
      memcpy(res + (i / 2), alf[position], sizeof(unsigned char));
      i++;
    }
  }
  return res;
}
