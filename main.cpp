#include <iostream>
#include "src/translit.h"
using namespace std;
int main() {
  unsigned char data[] = "КАРИНЭ";
  int len = sizeof(data);
  for (int i = 0; i <= len / 2; i++) {
    cout << transliter(data, len)[i];
  }
  return 0;
}
