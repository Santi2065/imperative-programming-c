#include <stdio.h>
#define DIVISOR(b,c) (b%c)==0?1:0
int main(void){
    printf("%d",DIVISOR(3,2));
}