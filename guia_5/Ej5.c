#include <stdio.h>

double pot(double n,int m){
int j=n;
for(int i=0;i<m;i++){
    j=j*n;
}
return j;
}

int main(void){
    printf("%f",pot(6,5));
}