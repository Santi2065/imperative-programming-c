#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList listUnion(TList list1,TList list2){
    if(list1==NULL&&list2==NULL){
        return NULL;
    }
    else if(list2!=NULL&&(list1==NULL || list1->elem>list2->elem)){
        TList definitiva = malloc(sizeof(TNode));
        definitiva->elem=list2->elem;
        definitiva->tail= listUnion(list1,list2->tail);
        return definitiva;
    }
    else if(list2==NULL || list1->elem<list2->elem){
        TList definitiva = malloc(sizeof(TNode));
        definitiva->elem=list1->elem;
        definitiva->tail= listUnion(list1->tail,list2);
        return definitiva; 
    }
    else{
        TList definitiva = malloc(sizeof(TNode));
        definitiva->elem=list1->elem;
        definitiva->tail= listUnion(list1->tail,list2->tail);
        return definitiva; 
    }
}