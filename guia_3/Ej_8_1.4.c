#include <stdio.h>
int main(void){
    int fahr, celsius;
    int lower, upper, step;
    lower=0;
    upper=300;
    step=20;
    celsius=lower;
    printf("Celsius\tFahrenheit\n");
    while(celsius <= upper){
        fahr=((celsius*9)/5)+32;
        printf("%d\t\t%d\n",celsius,fahr);
        celsius=celsius+step;
    }
}