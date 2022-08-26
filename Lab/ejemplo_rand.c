#include <stdio.h>
#include "random.h"

int main(void){
    randomize();
    int dados[5];
    int i;
    int generala = 0;
    for(i=0;i<5;i++){
        dados[i]=randInt(1,6);
        if(dados[i]==dados[0])
        generala = 1;
        else{
        generala = 0;break;}
    }
    if(generala==1)
    printf("Generala!!!");
    else
    printf("No generala");
}