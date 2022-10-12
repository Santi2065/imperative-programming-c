#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "getnum.h"

int getNivel(void){
    printf("%s\n","Elegir nivel:");
    int n;
    scanf("%d",&n);
    return n;
}

void rndmNum(int x,int n,int*num){
    srand(time(NULL));
    for(int i=0;i<x;i++){
        num[i]=((rand()%9)+1);
    }
    for(int j=0;j<x;j++){
        for(int i=0;i<x;i++){
            if(j==i)
                i++;
            if(num[j]==num[i]){
                if(num[j]==9){
                    num[j]=0;
                }
                num[j]++;
                j--;
            }
        }
    }
}

void readNum(int*guess,int x){
    int n=0;
    int aux=1;
    for(int j=0;j<(x-1);j++){
        aux*=10;
    }
    printf("%s\n","Ingrese su intento:");
    scanf("%d",&n);
    for(int i=0;i<x;i++){
        guess[i]=n/(aux);
        if(i!=0){
            guess[i]=guess[i]-((guess[i]/10)*10);
        }
            aux=aux/10;
    }
}

void check(int*guess,int*num,int x,int*bien,int*regular){
    *bien=0;
    *regular=0;
    char checker[10]={0};
    for(int j=0;j<x;j++){
        checker[num[j]]++;
    }
    for(int i=0;i<x;i++){
        if(guess[i]==num[i]){
            checker[guess[i]]--;
            *bien=*bien+1;
        }
    }
    for(int i=0;i<x;i++){
        if(checker[guess[i]]>0){
                checker[guess[i]]--;
                *regular=*regular+1;
            }
    }
}

int main(void){
    printf("%s\n","comenzamos el juego");
    int N=getNivel();
    int X=5;
    int num[X];
    int guess[X];
    int regular=0;
    int bien=0;
    rndmNum(X,N,num);
    for(int i=0;i<N;i++){
        readNum(guess,X);
        check(guess,num,X,&bien,&regular);
        printf("%d regular\n%d bien\nintento %d de %d\n",regular,bien,i+1,N);
        if(bien==X){
            printf("%s","ganaste!!!\n");
            return 0;
        }
    }
    printf("%s","perdiste :( \n");
    for(int i=0;i<X;i++){
        printf("%d",num[i]);
    }
    return 0;
}

