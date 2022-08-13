#include <stdio.h>
#include "getnum.h"

int
main(void){
    float vms = getfloat("Ingrese una velocidad en m/s: ");
    printf("%5.2fm/s son %5.2fkm/h\n", vms, (vms * 3.6));
}