#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

int sumAll(const TList list){
    if( list == NULL )
        return 0;
    return list->elem + sumAll(list->tail);
}

int odds1(const TList list){
    if( list == NULL )
        return 1;
    return list->elem%2 && odds1(list->tail);
}

int odds2(const TList list){
    if( list == NULL )
        return 0;
    if(list->tail==NULL)
        return list->elem%2;
    return list->elem%2 && odds2(list->tail);
}
