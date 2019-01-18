#include <iostream>
#include <string.h>

using namespace std;

char *translit(const unsigned char *data) {
  const char alf[][4] = {"A",  "B",   "V", "G", "D", "E",  "ZH", "Z", //4 (байт) -для сравнения с русскими буквами нужно вывести больше памяти 
                         "I",  "J",   "K", "L", "M", "N",  "O",  "P", 
                         "R",  "S",   "T", "U", "F", "H",  "C",  "CH",
                         "SH", "SCH", "",  "Y", "",  "EH", "JU", "JA"};
  int len = 0;
 // считаем количество символов
  while (data[len] != 0) { //data входное слово 
    len++;
  }
  char *res = new char[len / 2]; //создаем результирующий массив символов 
  int position = 0;              //позиция в alf
  int j = 0;                     //счётчик сдвига байтов
  //res составляемое слово
  for (int i = 0; i <= len; i++) {
    if (data[i] >= 0xd0 && data[i] <= 0xd1) { //0xd0 проверка не конец слова  
      position = data[i + 1] - 0x90; //0x90 место начала русского алфавита //находит адресс буквы 
      memcpy(res + j, alf[position], strlen((alf[position])));//(куда,откуда,длина) //копирует байты
      j = j + strlen(alf[position]);//j увеличеваем на длину строки символа
      i++;
    } else if (data[i] == ' ') {
      res[j] = ' '; 
      j++;
    }
  }
  return res;
}
