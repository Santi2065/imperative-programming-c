#include <stdio.h>
int depura(int v1[],int dim1,int v2[],int dim2){
    int i=0;
    int j=0;
    int new=0;
    if(dim2==0||dim1==0){
        return dim1;
    }
    while(i<dim1){
         if(v1[i]==v2[j]){
            if(i!=(dim1))
            i++;
            if(j!=(dim2))
            j++;
        }
        else{
            if(v1[i]<v2[j]){
                v1[new++]=v1[i];
                if(i!=(dim1))
                i++;
            }
            else{
                v1[new++]=v1[i];
                if(j!=(dim2))
                j++;
            }
        }
    }
    return new;
}

void main(){
int v1[7]={1,2,3,4,5,6,7};
int v2[7]={0,2,3,4,5,6,7};
printf("%d",depura( v1,7,v2,7));
}