#include <stdio.h>
#include "getnum.h"
int main(void){
    int a,b;
    a=getint("incerte 1er numero: ");
    b=getint("incerte 2do numero: ");
    if(b==0)
        printf("error, el 2do numero no puede ser 0\n");
    else
    {
    int c = (a%b==0?1:0);
    if (c==1)
        printf("es multiplo\n");
    else
        printf("no es multiplo\n");
    };
    return 0;

}