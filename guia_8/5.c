#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _loc {
    int x;
    int y;
    int time;
} location;

int main(void){
    location*turtle=malloc(sizeof(location));
    srand(time(NULL));
    turtle->x=0;
    turtle->y=0;
    turtle->time=0;
    int r;
    printf("%s","Inserte el radio: ");
    scanf("%d",&r);
    while(((turtle->x)*(turtle->x))+((turtle->y)*(turtle->y))<=(r*r)){
        switch((rand())%4){
            case 0:
                turtle->x++;
                break;
            case 1:
                turtle->x--;
                break;
            case 2:
                turtle->y++;
                break;
            case 3:
                turtle->y--;
                break;
        }
        turtle->time++;
    }
    double rel=((double)r/(double)(turtle->time));
    printf("time:%d,Radio:%d,Relacion:%.2f\n",turtle->time,r,rel);
}