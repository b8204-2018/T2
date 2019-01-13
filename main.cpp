#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

using namespace std;

int main() {

    assert(strcmp("VPERED, VPERED, NA ZOV SOHATIH", translit((const unsigned char *) "ВПЕРЕД, ВПЕРЕД, НА ЗОВ СОХАТЫХ")) == 0);
    assert(strcmp("NAVSTRECHU BESKONECHNIM MIRAM!", translit((const unsigned char *) "НАВСТРЕЧУ БЕСКОНЕЧНЫМ МИРАМ!")) == 0);
    assert(strcmp("VPERED, VO IMYA VSEH PERNATIH", translit((const unsigned char *) "ВПЕРЕД, ВО ИМЯ ВСЕХ ПЕРНАТЫХ")) == 0);
    assert(strcmp("NA POMOSCH' CHARODEYAM-KOTAM!", translit((const unsigned char *) "НА ПОМОЩЬ ЧАРОДЕЯМ-КОТАМ!")) == 0);

    return 0;
}


