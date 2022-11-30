#include "bible.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#define BLOCK 50

typedef struct verse {
    char** text;
    size_t dim;
} verse;

typedef struct bibleCDT {
    verse v[76];
} bibleCDT;

bibleADT newBible(void){
    return calloc(1,sizeof(bibleCDT));
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if(bible->v[bookNbr-1].dim<verseNbr){
        bible->v[bookNbr-1].text=realloc(bible->v[bookNbr-1].text,sizeof(char*)*(verseNbr+BLOCK));
        memset(bible->v[bookNbr-1].text + bible->v[bookNbr-1].dim, 0, (verseNbr+BLOCK) * sizeof(char *));
        bible->v[bookNbr-1].dim=verseNbr+BLOCK;
    }
    if(bible->v[bookNbr-1].text[verseNbr-1]!=NULL){
        return 0;
    }
    bible->v[bookNbr-1].text[verseNbr-1]=malloc(sizeof(char)*strlen(verse));
    strcpy(bible->v[bookNbr-1].text[verseNbr-1],verse);
    return 1;
}

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if(bookNbr>76||verseNbr-1>bible->v[bookNbr-1].dim||bible->v[bookNbr-1].text==NULL||bible->v[bookNbr-1].text[verseNbr-1]==NULL){
        return NULL;
    }
    char* hijoDePuta;
    hijoDePuta=malloc(strlen(bible->v[bookNbr-1].text[verseNbr-1])*sizeof(char));
    strcpy(hijoDePuta,bible->v[bookNbr-1].text[verseNbr-1]);
    return hijoDePuta;
}

void freeBible(bibleADT bible){
    for (size_t i = 0; i < 76; i++)
    {
        for (size_t j = 0; j < bible->v[i].dim; j++)
        {
            free(bible->v[i].text[j]);
        }
        free(bible->v[i].text);
    }
}

int
main(void) {
bibleADT b = newBible();
assert(getVerse(b, 1, 1)==NULL);
char aux[2000];
strcpy(aux, "En el principio creo Dios los cielos y la tierra.");
assert(addVerse(b, 1, 1, aux)==1);
strcpy(aux, "Y atardecio y amanecio: dia tercero.");
assert(addVerse(b, 1, 13, aux)==1);
assert(addVerse(b, 1, 13, "Amaos los unos a los otros")==0); // Ya estaba
strcpy(aux, "los contados de la tribu de Dan fueron sesenta y dos mil setecientos.");
assert(addVerse(b, 4, 39, aux)==1);
assert(addVerse(b, 4, 46,
"fueron todos los contados seiscientos tres mil quinientos cincuenta.")==1);
char * v = getVerse(b, 4, 45);
assert(v==NULL);
v = getVerse(b, 4, 39);
assert(strncmp(v, "los con", 7)==0);
free(v);
freeBible(b);
puts("Aleluya !");
return 0;
}