#include <stdio.h>
int main(void){
    printf("N\t10*N\t100*N\t1000*N\n\n");
    for(int n=1;n!=21;++n){
        printf("%d\t%d\t%d\t%d\n",n,n*10,n*100,n*1000);
    }
}