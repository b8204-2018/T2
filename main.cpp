#include "src/translit.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  assert(strcmp("VECHER DOBRYJ",
                transliter((const unsigned char *)"ВЕЧЕР ДОБРЫЙ")) == 0);
  assert(strcmp("SCHAVEL", transliter((const unsigned char *)"ЩАВЕЛЬ")) == 0);
  assert(strcmp("JA MAL", transliter((const unsigned char *)"Я МАЛ")) == 0);
  assert(strcmp("JA TUP", transliter((const unsigned char *)"Я ТУП")) == 0);
  assert(strcmp("SKILUHA PROKACHANA EEE",
                transliter((const unsigned char *)"СКИЛУХА ПРОКАЧАНА ЕЕЕ")) == 0);
  assert(strcmp("SCHAVEL MOJ DRUG",
                transliter((const unsigned char *)"ЩАВЕЛЬ МОЙ ДРУГ")) == 0);
  return 0;
}
