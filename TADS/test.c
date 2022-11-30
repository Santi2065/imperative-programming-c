typedef struct node * TList;

typedef struct node {
int elem;
struct node * tail;
} TNode;

void sortedList ( TList list ) {

    if(list==NULL||list->tail==NULL){
        return;
    }

    //corro la funcion para ver la lista de principio a fin

    sortedList(list->tail);

    // si el elemento proximo es menor o igual al actual, reemplazo el actual con el proximo

    if(list->tail->elem) <= (list->elem){

        aux=list->tail;

        list->elem=aux->elem;

        list->tail=aux->tail;

        free(aux);

    }

    return;

}