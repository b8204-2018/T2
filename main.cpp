#include <iostream>
#include <cstring>
#include "src/translit.h"
#include <cassert>

int main() {
    // use only small letters please
    std::cout << translit((const unsigned char*)"известный экономист, по призванию своему — библиотекарь. в народе — "
                                                "колхозник. в магазине — продавец.") << std::endl;

    assert(strcmp("ehlektricheskaja lampochka gorit ot sta dvadcati kirpichej, potomu chto struktura, tak skazat, "
                  "pohozha u nee na kirpich.", translit((const unsigned char *) "электрическая лампочка горит от ста "
                                      "двадцати кирпичей, потому что структура, так сказать, похожа у нее на кирпич.")) == 0);

    return 0;
}
