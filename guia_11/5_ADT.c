#include "5_ADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct complejoCDT
{
    float real;
    float imag;
}complejoCDT;

complejoADT complejoNuevo(float real, float imagi){
    complejoADT new;
    new->real=real;
    new->imag=imagi;
    return new;
}

complejoADT suma(complejoADT num1, complejoADT num2){
    complejoADT result;
    result=complejoNuevo(num1->real+num2->real,num1->imag+num2->imag)
    return result;
}

float parteReal(complejoADT num){
    return num->real;
}

float parteImag(complejoADT num){
    return num->imag;
}

void liberaComp(complejoADT num) {
    free(num);
}