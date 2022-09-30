#define DIM 4
#include <stdio.h>
static int perteneceFilaCol(int fila[], int m[][DIM], int j){
    int flag=1;
    for (int i=0; i < DIM && flag; i++){
        flag=0;
        for (int k=0; k < DIM && !flag; k++){
            if (fila[i] == m[k][j])
                flag=1;
        }
    }
    return flag;
}
static int control(int m1[][DIM], int m2[][DIM]){
    int flag=1;
    for (int i=0; i < DIM && flag!=0; i++){      //corta si llega al final, o encuentra 1 fila en la matriz que no cumplen la condicion
        flag=perteneceFilaCol(m1[i], m2, i);
    }
    return flag;
}
int belongs(int m1[][DIM], int m2[][DIM]){
    int a=1, b=1;
    
    a=control(m1, m2);
    if (a!=0){       //el ejercico indica que es indistino el retorno si cumple ambas condiciones
        b=control(m2, m1);  // de esta manera, con cumplir una, no recorre de nuevo las matrices
    }
    if (a)
        return 1;
    else return (b)?2:0;
}
 
int casos(const int m1[], int m2){
int i;
int encontre = 0;
 for(i = 0; i < DIM && !encontre; i++){
  if(m1[i] == m2)
   encontre = 1;
 } // for i
return encontre;
}
int matrices(const int m1[][DIM], const int m2[][DIM] ) {
 int i, j;
 int caso1 = 1;
 int caso2 = 1;
 int resp = 1;
 for (i =0; i < DIM && caso1 ; i++){
  for(j = 0; j < DIM && caso1 && resp; j++){
   resp = casos(m1[i], m2[j][i]);
  } // for j
   if (!resp )
     caso1 = 0; // entonces no devuelvo 1
 } // for i
if(!caso1){
 for (i =0; i < DIM && caso2 ; i++){
  resp = 1;
  for(j = 0; j < DIM && caso2 && resp ; j++){
   resp = casos(m2[i], m1[j][i]);
  } // for j
   if (!resp )
     caso2 = 0; // entonces no devuelvo 2
 } // for i
 if(caso2)
   return 2;
 } // if de caso1
else
  return 1;
return 0;
}

int matrix(int m1[DIM][DIM], int m2[DIM][DIM]){
    int mat1[DIM][DIM]={{0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};
    int mat2[DIM][DIM]={{0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};
for(int i=0;i<DIM;i++){
    for(int j=0;j<DIM;j++){
        for(int k=0;k<DIM;k++){
            if(m1[j][i]==m2[k][j]){
            mat1[j][i]++;}
            if(m2[j][k]==m1[i][j]){
            mat2[j][i]++;}
        }

    }
}
for(int i=0;i<DIM;i++){
    for(int j=0;j<DIM;j++){
        if(mat1[j][i]==0){
            for(int i=0;i<DIM;i++){
                for(int j=0;j<DIM;j++){
                    if(mat2[j][i]==0){
                    return 0;
                    }
                }
            }
            return 2;
        
        }    
    }
            
}
return 1;
}

int main(void){
int m1[DIM][DIM] = {{1,2,3,4},
                    {1,2,3,4},
                    {1,2,3,4},
                    {1,2,3,4}};
int m2[DIM][DIM] = {{1,2,3,4},
                    {1,2,3,4},
                    {1,2,3,4},
                    {1,2,3,4}};
printf("%d",matrix(m1,m2));
}

