#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    assert(strcmp("Moroz i solntse; den' chudesnyj!", translit((const unsigned char *)"Мороз и солнце; день чудесный!")) == 0);
    assert(strcmp("Eshche ty dremlesh', drug prelestnyj —", translit((const unsigned char *)"Еще ты дремлешь, друг прелестный —")) == 0);
    assert(strcmp("Pora, krasavitsa, prosnis':", translit((const unsigned char *)"Пора, красавица, проснись:")) == 0);
    assert(strcmp("Otkroj somknuty negoj vzory", translit((const unsigned char *)"Открой сомкнуты негой взоры")) == 0);
    assert(strcmp("Navstrechu severnoj Avrory,", translit((const unsigned char *)"Навстречу северной Авроры,")) == 0);
    assert(strcmp("Zvezdoyu severa yavis'!", translit((const unsigned char *)"Звездою севера явись!")) == 0);
    return 0;
}
