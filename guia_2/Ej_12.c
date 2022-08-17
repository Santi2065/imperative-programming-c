#include <stdio.h>
int main(void){
    char a=getchar();
    if ( a >= 'A' && a <= 'z')
        printf("%c es una letra", a);
    else
        printf("%c no es una letra", a);
    return 0;
}