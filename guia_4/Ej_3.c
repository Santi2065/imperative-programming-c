#define PI 3.1415
#define ESFERA(r) (4/3)*PI*r*r*r
#include <stdio.h>
int main(void){
for(int i=1;i<=10;++i){
printf("para radio %d, el volumen es %f\n",i, ESFERA(i));
}
return 0;
}
