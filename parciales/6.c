#include <stdio.h>
#include <string.h>
#include <ctype.h>
void elim(char*s){
    int i=0;
    int dim=strlen(s);
    char l=s[0];
    for(int n=1;n<=dim;n++){
        while(!isalpha(l)){
            s[i++]=l;
            l=s[n++];
        }
        if((tolower(l))!=tolower(s[n])){
            s[i++]=l;
            l=s[n];
        }
        l=s[n];
    }
    while(i<dim){
        s[i++]=0;
    }
}
void main(){
    char s[]={"aaA b[[[[b cc"};
    elim(s);
    printf("%s",s);
}