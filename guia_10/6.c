 #include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

 void deleteDupl(TList list){
 if(list==NULL || list->tail==NULL) return;

  if(list->elem==list->tail->elem){
    TList aux=list->tail->tail;
    free(list->tail);
    list->tail=aux;
    deleteDupl(list);
  }
  else deleteDupl(list->tail);
  }