#include <stdio.h>
#include <math.h>
#include "getnum.h"

int main(void){
  int a, b, c, d;
  float root1, root2;
  a = getint("ingrese a: ");
  b = getint("ingrese b: ");
  c = getint("ingrese c: ");
  d = (b*b)-4*a*c;
  if(a == 0)
   printf("no es una cuadratica\n");
  else
  if (d < 0)
    printf("complejo\n");
  else{
    root1 = ((-b)+sqrt(d))/(2*a);
    root2 = ((-b)-sqrt(d))/(2*a);
    printf("%.2f y %.2f\n",root1, root2);
  }
  return 0;
}
