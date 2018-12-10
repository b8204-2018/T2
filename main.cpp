#include <iostream>
#include <cstring>
#include <cassert>
#include "src/translit.h"

int main() {
    assert(strcmp("privet", translit((const unsigned char *) "привет")) == 0);
    assert(strcmp("Eto translit", translit((const unsigned char *) "Это транслит")) == 0);
    assert(strcmp("Translitom mozhno pisat\' tak", translit((const unsigned char *) "Транслитом можно писать так")) == 0);
    assert(strcmp("ILI VOT TAK", translit((const unsigned char *) "ИЛИ ВОТ ТАК")) == 0);
    assert(strcmp("A mOzhNo DaZHe TaK", translit((const unsigned char *) "А мОжНо ДаЖе ТаК")) == 0);
    assert(strcmp(":)", translit((const unsigned char *) ":)")) == 0);
    assert(strcmp("Glavnoe eto ne zabivat\'", translit((const unsigned char *) "Главное это не забывать")) == 0);
    assert(strcmp("CHto anglichane tebya ne poymut", translit((const unsigned char *) "Что англичане тебя не поймут")) == 0);
    assert(strcmp("Strochka s bukvoy sch", translit((const unsigned char *) "Строчка с буквой щ")) == 0);
    assert(strcmp("Sesh' [zhe] eschyo etih myagkih frantsuzskih bulok da vipey chayu", translit((const unsigned char *) "Съешь [же] ещё этих мягких французских булок да выпей чаю")) == 0);
    return 0;
}
