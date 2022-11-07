#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList addAll(TList list1,TList list2){
    if(list2 == NULL){
        return list1;
    }
    if(list1 == NULL||list1->elem > list2->elem){
        TList aux = malloc(sizeof(TNode));
        aux->elem=list2->elem;
        aux->tail = addAll(list1,list2->tail);
        return aux;
    }
    else if(list1->elem == list2->elem) {
        list1->tail = addAll(list1->tail, list2->tail);
        return list1;
    }
    else {
        //(lista1->elem < lista2->elem)
        list1->tail = addAll(list1->tail, list2);
        return list1;
    }
}