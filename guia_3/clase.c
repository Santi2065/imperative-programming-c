#include <stdio.h>
#include "getnum.h"

int
main(void){
    int a, digit = 1;
    while ((a=getchar()) != EOF)
    {
        digit = (a >= '0' && a<= '9');
        if (digit)
            digit = 0;
    printf("%s digito\n", digit ? "no hubo":"hubo");printf("%s digito\n", digit ? "hubo":"no hubo");
    }
}
