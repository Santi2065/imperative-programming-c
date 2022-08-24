#include <stdio.h>
int main(void){
    char c;
    int n=0;
    c=getchar();
    while((c!=EOF)){
        if(c==10||c==32||c==9)
        ++n;
        c=getchar();
    }
    printf("%i\n",n);
}