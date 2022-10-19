#include <stdlib.h>
#include <stdio.h>
int main(void){
char c = 'a';
char *p = malloc(sizeof(c));
*p=c;
}
