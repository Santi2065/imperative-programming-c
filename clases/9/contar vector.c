int contador(const int v[],unsigned int dim, int num){
    int n=0;
    for(int i=0;i<dim;++i){
        if(v[i]==num){
        ++n};
    }
    return n;
}
int pertenece(const int v[],unsigned int dim, int num){
    return contador(v,dim,num)>0;
}
int contadorMat(const int matriz[][dim],unsigned int fila, unsigned int cols, int num){
    int n=0;
    for(int i=0;i<fila;++i){
        n+=contador(matriz[i],cols,num);
    }
    return n;
}