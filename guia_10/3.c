#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList order(TList list){
    if(list==NULL)
        return list;
    if(list->elem>=list->tail->elem)
        list->elem=list->tail->elem;
    return order(list->tail);
}