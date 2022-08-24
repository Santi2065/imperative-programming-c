#define ENT_HORA 9
#define ENT_MINUTOS 30
#include <stdio.h>
#include "getnum.h"
int
llegaTemprano (const int hora, const int minutos)
{
return (hora <= ENT_HORA&&(hora <= ENT_HORA || minutos <= ENT_MINUTOS));
}

int main(void){
    int hora = getint("ingrese hora");
    int minutos = getint("ingrese minutos");
    printf("%s llego temprano",llegaTemprano(hora,minutos)?"si":"no");
}


