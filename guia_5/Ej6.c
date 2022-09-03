#include <stdio.h>
char mayMin(char a){
 char b = a + 32;
 return b;
}
char minMay(char a){
 char b = a - 32;
 return b;
}
char sigC(char a){
 char b = a + 1;
 return b;
}
char sigL(char a){
 char b = (a%26) + 79;
 return b;
}
int main(void){
    printf("%c\n%c\n%c\n",mayMin('Z'),minMay('z'),sigL('z'));
}