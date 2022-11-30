#include "synADT.h"


typedef struct node {
    char * synonym;
    struct node * tail;
} node;

typedef struct wordWithSyns {
    char * word;
    node * syns;
    struct wordWithSyns * tail;
} wordWithSyns;

struct dicSynCDT {
    size_t size; // cantidad de palabras
    wordWithSyns * first;
};

dicSynADT newDicSyn() {
    return calloc(1, sizeof(dicSynCDT));
}

size_t size(const dicSynADT dict) {
return dict->size:
}

/*
** Busca el nodo con la palabra word. Si no estaba lo agrega en forma ascendente
** y hace que node apunte al nuevo nodo.
** Si ya estaba entonces node apunta al nodo que contiene word
*/
static wordWithSyns * addWord( wordWithSyns * first, const char * word,
wordWithSyns ** node, int * flag ){
// NO COMPLETAR
}

void add(dicSynADT dict, const char * word, const char * synonymous) {
// Primero veo si hay que agregar word. Me retorna en un parámetro
// de salida una referencia al nodo, y en un flag retorna 0 si estaba o 1
// si lo agregó
wordWithSyns * theWord;
int flag = 0;
dict->first = addWord(dict->first, word, &theWord, &flag);
dict->size += flag;
// En theWord tenemos el puntero al nodo con la palabra word
// Completar el resto de la función
}

char ** synonyms(dicSynADT dict, const char * word) {
// Completar
}

char ** words(const dicSynADT dict) {
// Completar
}

void freeDict(dicSynADT dict) {
// NO completar
}


static void freeAll(char ** v) {
for(size_t i=0; v[i] != NULL; i++) {
free(v[i]);
}
free(v);
}

int main(void) {
dicSynADT dic = newDictSyn();
char ** aux;
aux = words(dic);
assert(aux[0] == NULL);
free(aux);
aux = synonyms(dic, "casa");
assert(aux[0] == NULL);
free(aux);
char word[50];
strcpy(word, "vivienda");
add("casa", word);
assert(size(dic)==2); // "casa" y "vivienda"
strcpy(word, "Hogar"); // Puede venir en minúscula o mayúscula
add("casa", word);
assert(size(dic)==3); // "casa", "Hogar" y "vivienda"
strcpy(word, "almondiga");
add("albondiga", word);
add("casa", "hogar"); // No realiza ningún cambio
aux = synonyms(dic, "Hogar");
assert(aux[0] == NULL);
free(aux);
assert(size(dic)==5);
aux = synonyms(dic, "CASA"); // "CASA" es lo mismo que "casa"
assert(strcmp(aux[0], "Hogar")==0);
assert(strcmp(aux[1], "vivienda")==0);
assert(aux[2] == NULL);
freeAll(aux);
aux = words(dic);
assert(strcmp(aux[0], "albondiga")==0);
assert(strcmp(aux[1], "almondiga")==0);
assert(strcmp(aux[2], "casa")==0);
assert(strcmp(aux[3], "Hogar")==0);
assert(strcmp(aux[4], "vivienda")==0);
assert(aux[5] == NULL);
freeAll(aux);
add("hogar", "casa"); // Ahora "casa" es sinónimo de "Hogar",
// pero el size no cambia, ya estaba "Hogar"
assert(size(dic)==5);
aux = synonyms(dic, "hogar");
assert(strcmp(aux[0], "casa")==0);
assert(aux[1] == NULL);
freeAll(aux);
freeDict(dic);
puts("OK, Correcto, Bien");
return 0;
}