#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList restaList(TList list1,TList list2){
    if(list1==NULL)
        return NULL;
    if(list2==NULL || list1->elem<list2->elem){
        TList newList=malloc(sizeof(TNode));
        newList->elem=list1->elem;
        newList->tail=restaList(list1->tail, list2);
        return newList;
    }
    else if(list1->elem > list2->elem){
        return restaList(list1, list2->tail);
    }

    else{ //list1->elem == list2->elem
        return restaList(list1->tail,list2->tail);
    }
}