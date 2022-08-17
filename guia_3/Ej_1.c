#include <stdio.h>
int main(void){
   char a;
   a=getchar();
   if(a>='A'&&a<='z'){
    if(a>'Z')
        printf("es ena letra minuscula\n");
    else
        printf("es una letra mayuscula\n");
   }
   else
    printf("no es una letra\n");
}