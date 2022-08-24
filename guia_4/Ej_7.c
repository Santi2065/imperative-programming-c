#define isdigit(l) (l>='A'&&l<='z')?1:0
#include <stdio.h>
int main(void){
    char l= getchar();
    if(isdigit(l))
    printf("es un digito");
    else
    printf("no es un digito");
    return 0; 
} 