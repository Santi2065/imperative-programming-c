#define FILS 3
#define COLS 4
#include <stdio.h>
int matrix(int mat[FILS][COLS]){
    int comp=mat[0][0],aux=0;
    for(int f=0;f<FILS;f++){
        for(int c=0;c<COLS;c++){
            if(comp<mat[f][c]){
                if(aux==-1){
                    return 0;
                }
                aux=1;
            }
            if(comp>mat[f][c]){
                if(aux==1){
                    return 0;
                }
                aux=-1;
            }
            comp=mat[f][c];
        }
    }
    return aux;
}
void main(){
    int m1[FILS][COLS] = {
        {19,13,12,8},
        {7,7,5,-1},
        {-6,-10,-14,-15}
    };
    printf("%d",matrix(m1));
}