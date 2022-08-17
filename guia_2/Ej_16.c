#include <stdio.h>
int main(void){
    char a,b;
    a=getchar();
    b=getchar();
    printf("%c es %s a %c\n",a,a>b?"mayor":(a<b?"menor":"igual"),b);
}