#include "vecADT.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct elemStruct{
    bool lleno;
    elemType elem;
} elemStruct;

typedef elemStruct * vecDinam;

typedef struct vectorCDT{
    size_t dim;
    size_t index;
    vecDinam vec;
} vectorCDT;

vectorADT newVector(void){
    return calloc(1,sizeof(vectorCDT));
}

void freeVector(vectorADT v){
    free(v->vec);
    free(v);
}

void putRec(vectorADT v, elemType * elems,size_t dim){
    
}

size_t put(vectorADT v, elemType * elems, size_t dim, size_t index){

}