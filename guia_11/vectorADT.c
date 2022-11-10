#include "vectorADT.h"
#include <stdlib.h>

typedef struct vectorCDT{
    elemType ** elems;
    size_t dim;
    elemType (*function) (elemType, char *)
} vectorCDT;

vectorADT newVector(elemType (*pfunc) (elemType, char *)){
    vectorADT aux = calloc(1,sizeof(vectorCDT));
    aux->function = pfunc;
    return aux;
}