#include "genericElem.h"
#include <stdlib.h>
#define BLOCK 5

typedef struct vector{
    elemType* v;//vector de elementos
    char* is;   //vector de dimension del vector
}vector;

typedef struct collectionCDT{
    vector* vect;
    size_t mem; //memoria alocada
    size_t dim; //dim   
    int (*compare)(elemType a,elemType b);
} collectionCDT;

collectionADT newCollection(int (*compare)(elemType a,elemType b)){
    collectionADT o=calloc(1,sizeof(collectionCDT));
    o->compare=compare;
    return o;
}

int elementCount(collectionADT c){
    return c->dim;
}

void putElement(collectionADT c, elemType elem, size_t pos){
    if(pos>c->mem){
        c->vect=realloc(c->vect,sizeof(elemType)*(pos+BLOCK)*2);
        for(int i=c->mem;i<pos+BLOCK;i++){
            c->vect->is[i]=0;
            c->vect->v[i]=0;
        }
        c->mem=pos+BLOCK;
    }
    if(c->vect->is[pos]==0){
        c->vect->is[pos]=1;
        c->dim++;
    }
    c->vect->v[pos]=elem;
}

void deleteElement(collectionADT c, size_t pos){
    if(pos>c->mem){
        return;
    }
    c->vect->v[pos]=0;
    c->vect->is[pos]=0;
}

int getPosition(collectionADT c, elemType elem){
    for(int i=0;i<c->mem;i++){
        if(c->compare(c->vect->v[i],elem)){
            return i;
        }
    }
    return -1;
}

void freeCollection(collectionADT c){
    free(c->vect);
}

void main(){

}