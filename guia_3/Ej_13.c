#include <stdio.h>
int main(void){
    /*
    int l=1,n=1,m=5;
    while(l<=m){
    while(n<=m){
        printf("*");
        ++n;
    }
    printf("\n");
    ++l;
    n=1;}
    */
   int m=5;
   for(int i=1;i<=((m*m)+m);++i){
    if(i%(m+1)==0)
    printf("\n");
    else
    printf("*");
   }
}