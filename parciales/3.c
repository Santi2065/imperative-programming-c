#include <stdio.h>
#include <string.h>
int endsWith(char*s1,char*s2){
    int flag1=strlen(s1),flag2=strlen(s2);
    if(flag1>flag2)
        return 0;
    while(flag2>=0){
        if (s1[flag1]!=s2[flag2]){
            return 0;
        }
        flag1--;
        flag2--;
    }
    return 1;

}

void main(void){
    printf("%d",endsWith("hola","hola"));
}