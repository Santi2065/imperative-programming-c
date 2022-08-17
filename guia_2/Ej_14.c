#include <stdio.h>
#include "getnum.h"
int main(void){
int a,b;
a=getint("Ingrese un numero: ");
b=getint("numero 2: ");
printf("el promedio es %d\nLa suma es %i\nEl menor es %i\nEl mayor es %i\n%s",(a+b)/2, a+b,a<b?a:b,a>b?a:b,(a==b)?"son iguales\n":"son distintos\n");
}