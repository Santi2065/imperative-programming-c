#include <stdio.h>
int
main(void){
    int edad = 25;
    float longitud = 185.654;
    char letra = 'Z';
printf("tengo = %-5d\n", edad);
printf("tengo = %10d\n", edad);
printf("me mide = %10.2f\n", longitud);
printf("y mi letra favorita es = %8i\n", letra);
}