#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    assert(strcmp("Ublyudok, mat' tvoyu", translit((const unsigned char *)"Ублюдок, мать твою")) == 0);
    assert(strcmp("a nu idi syuda govno sobach'e,", translit((const unsigned char *)"а ну иди сюда говно собачье,")) == 0);
    assert(strcmp("reshil ko mne lezt'?", translit((const unsigned char *)"решил ко мне лезть?")) == 0);
    assert(strcmp("Ty, zasranets vonyuchij, mat' tvoyu, a?", translit((const unsigned char *)"Ты, засранец вонючий, мать твою, а?")) == 0);
    assert(strcmp("Nu idi syuda,", translit((const unsigned char *)"Ну иди сюда,")) == 0);
    assert(strcmp("poprobuj menya trahnut'...", translit((const unsigned char *)"попробуй меня трахнуть...")) == 0);
    return 0;
}