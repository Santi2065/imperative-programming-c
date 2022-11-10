#include "listADT.h"
#include <stdio.h>
#include <stdlib.h>


elemType get(listADT list,unsigned int idx){
    int i;
    listADT auxi;
    if(idx>=list->size){
        fprintf(stderr,"Error: indice fuera de rango");
        exit(1);
    }
    auxi = list->first;
    for(i=0; i<idx; i++)
            auxi = auxi->tail;
    return auxi->head;

}