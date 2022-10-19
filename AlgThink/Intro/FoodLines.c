#include<stdio.h>
#define MAX 100
int main(void){
int fila[MAX];
int n,m,aux;
scanf("%d %d",&n,&m);
for(int l=0;l<n;l++){
    scanf("%d",&fila[l]);
}
int menor=fila[0];
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(menor>=fila[j]){
            menor=fila[j];
            aux=j;
        }
    }
    printf("%d\n",fila[aux]);
    fila[aux]++;
    menor=fila[0];
}
}