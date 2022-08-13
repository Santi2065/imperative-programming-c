#include <stdio.h>
#include "getnum.h"

int
main(void)
{
    int tiempo = getint("ingrese los segundos: \n");
    printf(" segundos son %i horas, %i minutos y %i segundos\n", tiempo/3600, (tiempo % 3600)/60, tiempo % 60);
    return 0;
}
