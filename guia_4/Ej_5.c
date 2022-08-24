#define MAXIMO2(t,x,y) t=(x>y)?x:y
#include <stdio.h>
int main(void){
    int t, x=1, y=2;
    MAXIMO2(t,x,y);
    printf("t=%d\n",t);
}