#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

void order(TList list){
    if(list == NULL || list->tail == NULL)
        return;
    if(list->elem>=list->tail->elem){
        TList aux = list->tail;
        list->tail=aux->tail;
        free(aux);
        order(list);
    }
    else
        order(list->tail);
}