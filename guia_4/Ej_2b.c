#define PI 3.14
#include <stdio.h>
int main(void){
    float a=0;
    float b;
    b=PI+a++;
    printf("%f %f %f",a, b, PI);
    return 0;
}