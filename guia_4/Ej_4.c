#define swap(t,x,y) t=x, x=y, y=t
#include <stdio.h>
int main(void){
    int t, x=1, y=2;
    swap(t,x,y);
    printf("x=%d,y=%d\n",x,y);
}