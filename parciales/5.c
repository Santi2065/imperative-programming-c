#include <stdio.h>
int vect(const int*v, const int dim,int*menor,int*mayor,float*prom){

    if(v[0]==0){
        return 0;
    }
    for(int n=1;n<dim;n++){
        if(v[n]<*menor){
            *menor=v[n];
        }
        if(v[n]>*mayor){
            *mayor=v[n];
        }
        *prom=*prom+v[n];
    }
    *prom=(*prom/dim);
    return 1;
}

int main (){

    int v[3]={1,10,3};
    int mayor=v[0],menor=v[0];
    float prom=0;
    vect(v,3,&mayor,&menor,&prom);
     printf("el mayor es:%d, el menor es:%d, el promedio es:%.2f",mayor,menor,prom);
}