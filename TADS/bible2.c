#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define BLOCK 50

typedef struct book
{
    char **verses;
    size_t size;
} Book;

struct bibleCDT
{
    Book books[76];
};

typedef struct bibleCDT *bibleADT;

bibleADT newBible()
{
    bibleADT bible = calloc(1, sizeof(struct bibleCDT));

    return bible;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char *content)
{
    if (bookNbr > 76)
        return 0;

    Book *book = &bible->books[bookNbr - 1];

    if (verseNbr > book->size)
    {
        book->verses = realloc(book->verses, sizeof(char *) * (book->size + BLOCK));

        memset(book->verses + book->size, 0, BLOCK * sizeof(char *));
    }

    char **verse = &book->verses[verseNbr - 1];

    if (*verse)
    {
        return 0;
    }

    *verse = malloc(strlen(content));
    strcpy(*verse, content);
    return 1;
}

char *getVerse(bibleADT bible, size_t book, size_t verse)
{
    if (book > 76 || !bible->books[book - 1].verses || verse > bible->books[book - 1].size)
    {
        return 0;
    }

    return bible->books[book - 1].verses[verse - 1];
}

void freeBible(bibleADT bible)
{
    for (size_t i = 0; i < 76; i++)
    {
        Book *book = &bible->books[i];
        for (size_t i = 0; i < book->size; i++)
        {
            free(book->verses[i]);
        }
        free(book->verses);
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