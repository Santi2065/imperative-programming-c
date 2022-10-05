#include <stdio.h>
#include <string.h>
#include "getnum.h"
#include "getline.h"
#include <errno.h>
#include <stdlib.h>

#define MAX 30
#define ISBEN_MAX 10

typedef struct tipoLibro {
    char    titulo[MAX+1];
    char    autor[MAX+1];
    char    ISBN[ISBEN_MAX + 1];
    float   precio;
} tipoLibro;

/* Funcion que carga un libro */
void carga (tipoLibro * libro);

/* Funcion que imprime el libro */
void imprime(const tipoLibro * libro);

int 
main4(void)
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

    free(biblioteca);
    
	return 0;
}

void 
carga (tipoLibro * libro)
{
	printf("Titulo: ");
    getLine(libro->titulo, MAX);
    printf("Autor: ");
    getLine(libro->autor, MAX);
    printf("ISBN: ");
    getLine(libro->ISBN, ISBEN_MAX);
    libro->precio = getfloat("Precio:");
}	

void 
imprime(const tipoLibro * libro)
{
	printf("Titulo: %s ", libro->titulo);
	printf("Autor: %s \n", libro->autor);
	printf("ISBN: %s ", libro->ISBN);
	printf("Precio: %g \n", libro->precio);
}	

