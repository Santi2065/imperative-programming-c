#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList removeIf(TList list,int (*criteria)(int)){
    if(list==NULL){
        return NULL;
    }
    if (criteria(list->elem)) {
        TList aux = list->tail;
        free(list);
        return removeIf(aux, criteria);
    }
    list->tail = removeIf(list->tail, criteria);
    return list;
}