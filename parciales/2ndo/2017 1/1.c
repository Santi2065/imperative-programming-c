#include <stdio.h>
#include <stdlib.h>
typedef struct node * Tnode; 
typedef struct node {
    int elem;
    struct node * tail;
} node;

Tnode vecListsinRep(int *v){
    if(*v==-1){
        return NULL;
    }
    Tnode aux=malloc(sizeof(Tnode));
    while(*v==*++v){}
    aux->elem=*(--v);
    aux->tail=vecListsinRep(++v);
    return aux;
}

Tnode vecList(int *v){
    if(*v==-1){
        return NULL;
    }
    Tnode aux=malloc(sizeof(Tnode));
    aux->elem=*v;
    aux->tail=vecList(++v);
    return aux;
}



Tnode listCpy(Tnode d){
    if(d==NULL){
        return NULL;
    }
    Tnode list= d;
    if(list==NULL||d->elem == list->elem){
        Tnode aux1 = malloc(sizeof(Tnode));
		aux1->elem = d->elem;
		aux1->tail = d;
		return aux1;
    }
    Tnode aux=malloc(sizeof(Tnode));
    aux->elem=list->elem;
    aux->tail=listCpy(list->tail);
    return aux;
}

Tnode printL(Tnode list){
    if(list==NULL){
        return NULL;
    }
    printf("%d\n",list->elem);
    printL(list->tail);
}

void main(){
    int v[9]={1,2,2,4,4,6,6,6,-1};
    printL(listCpy(vecList(v)));
}

