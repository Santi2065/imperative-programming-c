#include <stdio.h>
int main(void){
char a;
a=getchar();
printf("%c\n",a<'a'?(a):(a+('A'-'a')));
}