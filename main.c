#include <stdio.h>

#include <stdlib.h>

char* ithword(char* str,int i){
// create new char data
  char *chars = (char *)malloc(sizeof(char)*i);
  int myindex = 0;
  
  for (int index = 0; index < i; index++) {
    char c = str[index];
    // accepts only A - Z
    if ((int)c >= 65 && (int)c <= 90) {
      chars[myindex] = c;
      myindex++;
      }
      // accepts only a - z
    else if ((int)c >= 97 && (int)c <= 122) {
      chars[myindex] = c;
      myindex++;
      }
      // accepts only 0 - 9
    else if ((int)c >= 48 && (int)c <= 57) {
      chars[myindex] = c;
      myindex++;
      }
    }
  return chars;
}

int main(){

  char str[]="#$%test3^%$^45";

  printf("Orignal string : %s\n",str);

  char* s = ithword(str,14);

  printf("Converted string : %s\n",s);

}