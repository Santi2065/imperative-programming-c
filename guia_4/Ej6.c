#define MAXIMO2(t,x,y) t=(x>y)?x:y
#define MAXIMO3(t,x,y,z) t=((MAXIMO2(t,x,y)>z))?t:z
#include <stdio.h>
int main(void){
    int t, x=3, y=1, z=2;
    MAXIMO3(t,x,y,z);
    printf("t=%d\n",t);
}