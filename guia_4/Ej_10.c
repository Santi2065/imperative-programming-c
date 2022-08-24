#include <stdio.h>
int
mcd (int a, int b)
{
int auxi=1;
while (auxi>0)
{
auxi = a % b ;
a = b;
b = auxi;

}
return a;
}
int main(void){
    printf("%i",mcd(27,378));
}