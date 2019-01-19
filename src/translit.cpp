#include "translit.h"
#include<string>
#include <cstring>

using namespace  std;

char *translit(const unsigned char *s) {
	const char Alph[][4] = { "A", "B", "V", "G", "D", "E", "ZH", "Z", "I", "Y", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F",
								 "H", "TS", "CH", "SH", "SCH", "", "I", "'", "E", "YU", "YA" };

	int n = 0;
	int pos = 0;
	while (s[n] != '\0') {
		n++;
	}
	
	char *result = new char[n * 4];
	int  j = 0;
	for (int i=0; i < n; i++) {
		if (s[i] == 0xd0 || s[i] == 0xd1) { //
			pos = s[i + 1] - 0x90;// номер символа для транслита в массиве
			memcpy(result + j, Alph[pos], strlen(Alph[pos]));
			j += strlen(Alph[pos]);
			i++;
		}
		else {
			memcpy(result + j, s + i, 1);// если не является буквой русского алфавита
			j++;
		}
	}
	result[j] = '\0';
	return result;

}

