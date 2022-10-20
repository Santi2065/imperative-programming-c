#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char* str(char*s,char c){
    if(*s!='\0'){
        if(*s==c){
            return(s);
        }
        return str(++s,c);  
    }
    return NULL;
}
int main(){
    char *s = "lifeisgood";
    printf("%s",str(s,' '));
    return 0;

}