#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    //проблемы с этими 3мя буквами
    char *s = translit((const unsigned char *) "Ййш"); //Отображаются как "�\231�\271�\210"
    //pos не вычисляется
    //для других букв вроде работает
    assert(strcmp(translit((const unsigned char *) "Moroz i solntse; den' chudesnyj!"), "Мороз и солнце; день чудесный!") == 0);
    assert(strcmp(translit((const unsigned char *) "Eshche ty dremlesh', drug prelestnyj"), "Еще ты дремлешь, друг прелестный —") == 0);
    assert(strcmp(translit((const unsigned char *) "Pora, krasavitsa, prosnis':"), "Пора, красавица, проснись:") == 0);
    assert(strcmp(translit((const unsigned char *) "Otkroy somknuty negoj vzory"), "Открой сомкнуты негой взоры") == 0);
    assert(strcmp(translit((const unsigned char *) "Navstrechu severnoj Avrory,"), "Навстречу северной Авроры,") == 0);
    assert(strcmp(translit((const unsigned char *) "Zvezdoyu severa yavis'!"), "Звездою севера явись!") == 0);
    return 0;
}
