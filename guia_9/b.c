#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int str(char*s){
    if(*s!='\0'){
        return 1+str(++s);  
    }
    return 0;
}
int main(){
    char *s = "lifeisgood";
    printf("%d",str(s));
    return 0;

}