#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTNUMB 15
#define NUMB 0
#define ISNUMB 1

void generarCarton(carton[2][TOTNUMB]){
    srand(time(NULL));
    for(int i=0;i<TOTNUMB;i++){
        carton[NUMB][i]=((rand()%90)+1);
    }
    for(int i=0;i<TOTNUMB;i++){
        for(int j=0;j<TOTNUMB;j++){
            if(i==j)
            else(carton[NUMB][i]==carton[2][j]){
                if(carton[NUMB][i]==90)
                    carton[NUMB][i]=0;
                carton[NUMB][i]++;
            }
        }
    }
}

int extractor(char*bolillero,char*jugador1,char*jugador2){
    srand(time(NULL));
    int x=(rand()%90);
    while(1==bolillero[1][x]){
        int x=(rand()%90);
    }
    bolillero[1][x]=1;
    return x;
}

int main(void){
    
}