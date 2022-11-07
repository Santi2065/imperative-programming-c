#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList listIntersec(TList list1,TList list2){
    if(list1==NULL||list2==NULL){
        return NULL;
    }
    if(list1->elem==list2->elem){
        TList definitiva = malloc(sizeof(TNode));
        definitiva->elem=list1->elem;
        definitiva->tail= listIntersec(list1->tail,list2->tail);
        return definitiva; 
    }
    else if(list1->elem>list2->elem){
        return listIntersec(list1,list2->tail);
    }
    else{
        return listIntersec(list1->tail,list2);
    }
}