typedef struct node{
    
}node;

dictADT newDict(){
    return calloc(1,sizeof(dictCDT))
}

void freeDict(dictADT m){
    free(m);
}