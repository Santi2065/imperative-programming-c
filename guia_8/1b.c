#include <stdlib.h>
#include <stdio.h>
struct art {
    int code;
   double price;
};

struct art * newArt(int c, double r) {
    struct art * p = calloc(1, sizeof(struct art));
    p->code = c;
    p->price = r;
    return p;
}

int main(void){
}