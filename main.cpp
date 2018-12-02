#include "src/translit.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  assert(strcmp("VECHERDOBRYJ", transliter((const unsigned char *)"ВЕЧЕРДОБРЫЙ",
                                           sizeof("ВЕЧЕРДОБРЫЙ"))) == 0);
  assert(strcmp("SCHAVEL", transliter((const unsigned char *)"ЩАВЕЛЬ",
                                      sizeof("ЩАВЕЛЬ"))) == 0);
  assert(strcmp("JAMAL", transliter((const unsigned char *)"Я МАЛ",
                                    sizeof("Я МАЛ"))) == 0);
  assert(strcmp("JATUP", transliter((const unsigned char *)"Я ТУП",
                                    sizeof("Я ТУП"))) == 0);
  assert(strcmp("SKILUHAPROKACHANAEEE",
                transliter((const unsigned char *)"СКИЛУХА ПРОКАЧАНА ЕЕЕ",
                           sizeof("СКИЛУХА ПРОКАЧАНА ЕЕЕ"))) == 0);
  return 0;
}
