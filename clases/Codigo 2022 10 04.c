#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10

/**
 * Asumimos que el string es corto !!!!
 * @return una copia modificable del string
 */
char * copyStr(const char * s) {
    char * ans = malloc(strlen(s)+1);
    strcpy(ans, s);
    //for(int i=0; ans[i]=s[i]; i++)
    //    ;
    return ans;
}

/**
 *
 * @param p el puntero actual con un string
 * @param s el string que quiero copiar a p
 * @return
 */
char * copyStr2(char * p, const char * s) {
    // si realloc recibe NULL hace lo mismo que malloc
    p = realloc(p, strlen(s)+1);
    strcpy(p, s);
    //for(int i=0; ans[i]=s[i]; i++)
    //    ;
    return p;
}

/**
 * Completa el vector s con la línea o hasta leer max chars
 * @param s
 * @param max
 * @return la longitud del string leido
 */
size_t getLine(char * s, size_t max) {
    int c, i=0;
    while ( ( c = getchar()) != '\n') {
        if ( i < max) {
            s[i++] = c;
        }
    }
    s[i] = 0;
    return i;
}
// Queda como ejercicio hacer una funcion getline que no tenga límites
// O sea, que retorne un string sin limite de longitud

int main() {

    int cantidad = 10; // leer con getint
    // Luego cantidad puede cambiar, ser mas o menos

    char ** nombres;
    nombres = malloc(cantidad * sizeof(nombres[0]));
    char aux[MAX_LENGTH+1];

    for(int i=0; i < cantidad; i++) {
        // Leemos en el vector auxiliar
        nombres[i] = malloc(getLine(aux, MAX_LENGTH) + 1);
        strcpy(nombres[i], aux);
    }

    // Imprimimos
    for(int i=0; i<cantidad; i++){
        puts(nombres[i]);
    }

    // Se agrega un jugador
    size_t nuevoLen = getLine(aux, MAX_LENGTH);
    cantidad++;
    nombres = realloc(nombres, cantidad * sizeof(*nombres));
    nombres[cantidad-1] = malloc(nuevoLen+1);
    strcpy(nombres[cantidad-1], aux);



    // Queremos que el primer palo sea "Esto era una copa"
    // nombres[0] = copyStr2(nombres[0], "Esto era una copa");


    // Liberamos la memoria
    // Primero cada uno de los trings
    for(int i=0; i<cantidad; i++){
        free(nombres[i]);
    }
    // Segundo el vector de punteros a char
    free(nombres);

    return 0;
}
