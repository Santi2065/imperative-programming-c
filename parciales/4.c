#include <stdio.h>
void eliminar(char*s){
    char charCount[127]={0};
    for(int i=0;s[i]!=0;++i){
        ++charCount[s[i]];
    }
    int i=0,j=0;
    while(s[i]!=0){
        if(charCount[s[i]]>1){
            --charCount[s[i]];
        }
        else{
            s[j++]=s[i];
        }
        ++i;
    }
s[j]=0;
    printf("%s\n",s);

}
void main(){
    char s[]={"abcbc.cba"};
    eliminar(s);
}