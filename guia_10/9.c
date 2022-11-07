#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"
typedef struct nodeBrief * TListBrief;

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
	} TNodeBrief;


TListBrief comprimeList(TList list){
    if(list==NULL){
        return NULL;
    }
    TListBrief bl = comprimeList(list->tail);
    if ( bl == NULL || list->elem < bl->elem) {
		TListBrief aux = malloc(sizeof(TNodeBrief));   // El nuevo header de la sublista abreviada
		aux->elem = list->elem;
		aux->count = 1;
		aux->tail = bl;
		return aux;
	}
    bl->count++;
	return bl;
}