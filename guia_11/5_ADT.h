#ifndef COMPLEJO_ADT_H
#define COMPLEJO_ADT_H

typedef struct complejoCDT *complejoADT;

complejoADT complejoNuevo(float real, float imagi);

complejoADT suma(complejoADT num1, complejoADT num2);

float parteReal(complejoADT num);

float parteImag(complejoADT num);

void liberaComp(complejoADT num);

#endif
