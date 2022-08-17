#include <stdio.h>
#include "getnum.h"
int main(void){
    int a=getint("Ventas brutas: ");
    if(a>4000)
        printf("Le corresponde $%.0f\n",300+(0.09*a));
    else{
        if(a>2000)
            printf("Le corresponde $%.0f\n",300+(0.07*a));
        else{
            if(a>1000)
            printf("Le corresponde $%.0f\n",300+(0.05*a));
            else
            printf("Le corresponde $%d\n",300);
            }}}