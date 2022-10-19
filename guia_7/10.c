#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#define BORRA_BUFFER while (getchar() != '\n')

void selPalabra(char a[10],char guess[10],const char pal[6][10],int*len){
    int b=rand()%6;
    for(int i=0;i<10;i++){
        a[i]=pal[b][i];
    }
    *len=strlen(a);
    for(int i=0;i<*len;i++){
        guess[i]='*';
    }
}

void print(char*guess){
    printf("%s\n", guess);
}

int check(int*len,char guess[10],char a[10],char*c){
    int flag=0;
    printf("%s","intenta adivinar: ");
    scanf("%c",c);
    for(int i=0;i<10;i++){
        if(a[i]==*c){
            guess[i]=*c;
            flag=1;
        }
    }
    BORRA_BUFFER;
    print(guess);
    return flag;
    
}


int main(void){
    srand(time(NULL));
    char c;
    int len;
    int intentos=6;
    const char diccionario[6][10]={"arbol","casa","cielo","tomate","papa","zanahoria"};
    char a[10],guess[10];
    selPalabra(a,guess,diccionario,&len);
    printf("%d%s",len," letras\n");
    print(guess);
    for(int i=0;i<6;){
        if((check(&len,guess,a,&c))==0)
            ++i;
        if((strcmp(guess,a))==0){
            printf("%s\n","Ganaste!!!");
            return 0;
        }
    }
printf("%s\n","perdiste");
}