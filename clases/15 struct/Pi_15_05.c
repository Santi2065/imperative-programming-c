#include <stdio.h>
#include <string.h>
#include "getnum.h"
#include "getline.h"
#include <errno.h>
#include <stdlib.h>

#define ISBEN_MAX 10

typedef struct tipoLibro {
    char *  titulo;
    char *  autor;
    char    ISBN[ISBEN_MAX + 1];
    float   precio;
    unsigned int     paginas;
} tipoLibro;

/* Funcion que carga un libro */
void carga (tipoLibro * libro);

/* Funcion que imprime el libro */
void imprime(const tipoLibro * libro);

void freeLibrary(tipoLibro * bib, unsigned int dim);

int 
main(void)
{
	tipoLibro * biblioteca;
	int i, cant;

	/* Se solicita la cantidad de libros de la biblioteca */
	while ((cant = getint("Ingrese la cantidad de libros:")) <= 0) 
			;

	/* Se crea la biblioteca */
    errno = 0;
	if ((biblioteca = malloc(cant  * sizeof(tipoLibro))) == NULL || errno != 0)
	{
		fprintf(stderr, "Error en malloc.\n");
		return 1;
	}
		
	/* Se leen los libros */
	for (i=0; i< cant; i++)
		carga(&biblioteca[i]);   

	/* Se imprimen los libros */
	for (i=0; i< cant; i++)
		imprime(biblioteca+i);   

    freeLibrary(biblioteca, cant);
	return 0;
}

void freeLibrary(tipoLibro * bib, unsigned int dim) {
    for(int i=0; i < dim; i++) {
        free(bib[i].titulo);   // free ( (bib + i)->titulo)
        free(bib[i].autor);
    }
    free(bib);
}

void 
carga (tipoLibro * libro)
{
    int dimAux;
	printf("Titulo: ");
    libro->titulo = getlineNoLimit(&dimAux);
    printf("Autor: ");
    libro->autor = getlineNoLimit(&dimAux);
    printf("ISBN: ");
    getLine(libro->ISBN, ISBEN_MAX);
    libro->precio = getfloat("Precio:");
    libro->paginas = getint("Páginas:");
}	

void 
imprime(const tipoLibro * libro)
{
	printf("Titulo: %s ", libro->titulo);
	printf("Autor: %s \n", libro->autor);
	printf("ISBN: %s ", libro->ISBN);
	printf("Precio: %g \n", libro->precio);
	printf("Páginas: %d \n", libro->paginas);
}	

