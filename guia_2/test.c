#include <stdio.h>
int main(void) {
   int a,b;
   printf("%s","Type two numbers to test if theyre the same,\n");
   printf("%s","Number 1: ");
   scanf("%d",&a);
   printf("%s","Number 2: ");
   scanf("%d",&b);
   if (a==b){
      printf("\n%d%s%d%s",a," y ",b," son iguales");
   }
   else{
      printf("%d%s%d%s",a," y ",b," no son iguales");
   }
   return 0;
}