#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("Ya srazu smazal kartu budnya,", translit((const unsigned char *) "Я сразу смазал карту будня,")) == 0);
    assert(strcmp("plesnuvshi krasku iz stakana;", translit((const unsigned char *) "плеснувши краску из стакана;")) == 0);
    assert(strcmp("ya pokazal na blyude studnya", translit((const unsigned char *) "я показал на блюде студня")) == 0);
    assert(strcmp("kosye skuly okeana.", translit((const unsigned char *) "косые скулы океана.")) == 0);
    assert(strcmp("Na cheshue zhestyanoj ryby", translit((const unsigned char *) "На чешуе жестяной рыбы")) == 0);
    assert(strcmp("prochel ya zovy novyh gub.", translit((const unsigned char *) "прочел я зовы новых губ.")) == 0);
    assert(strcmp("A vy noktyurn sygrat' mogli by na flejte vodostochnyh trub?", translit((const unsigned char *) "А вы ноктюрн сыграть могли бы на флейте водосточных труб?")) == 0);
    return 0;
}
