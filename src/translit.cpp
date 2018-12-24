#include "translit.h"
#include <string.h>
#include <iostream>
#include <cstring>

using namespace std;
char *translit(const unsigned char *s) {
    const char sbl[][4]{"A","B","V","G","D","E","ZH","Z","I","IY","K","L","M","N",
                        "O","P","R","S","T","U","F","HA","TS","CH","SH", "SHY","''",
                        "Y","`","EH","YU","YA"};
    int j=0;
    while (s[j]!=0){
        j++;
    };
    //j/=2;
    int k =0;
    int position = 0;
    char *result = new char[j];
    for (int i=0;i<j;i++){
        if (s[i]>=0xd0 && s[i]<=0xd1) {
            position = (s[i + 1] - 0x90);
            memcpy(result + k, sbl[position], strlen(sbl[position]));
            k = k+strlen(sbl[position]);
        }
        }

    return result;
}