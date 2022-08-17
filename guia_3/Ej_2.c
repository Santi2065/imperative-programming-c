#include <stdio.h>
int main(void){
char a,b;
a=getchar();
b=getchar();
if(a>=b){
    if(a>b)
        printf("%c es mayor a %c\n",a,b);
    else
        printf("%c es igual a %c\n",a,b);
}
else
printf("%c es menor a %c\n",a,b);
}