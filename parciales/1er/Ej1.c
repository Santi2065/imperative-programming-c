#include <stdio.h>
#include <ctype.h>

void normalizar(char * s)
{
    int count=0,dim=0,aux=0;
    printf("%d",1);
    fflush(stdout);
    for(int i=0;s[i]!=0;i++){
        if(s[i]=='.'){
            s[dim++]=s[i++];
            while(s[i]!=','&&s[i]!=0){
                if(count<2){
                    s[dim++]=s[i];
                }
                count++;
                i++;
            }
            s[dim++]=s[i];
            if(s[i]==',')
            i++;
            count=0;
        }
        else
        s[dim++]=s[i];
    }
}


void normalizare(char * s) {
    int i, dim=0, count =0;
    char anterior=0;
    for (i=0 ; s[i] != '\0' ; i++) {
        if( anterior == ',' || i == 0 )
            while(s[ i ]  !=  '.' )
                s[dim++] = s[i++];
        if(! isdigit( s[i] ))
            s[dim++] = s[ i ];
        else if( anterior == '.' )
            count=2;
        if(count > 0) {
            if(isdigit( s[ i ] ) ){
                s[dim++] = s[ i ];
            }
            count--;
        }
        anterior = s[ i ];
    }
  s[dim] = 0;
}


int main(void){
char string[] = "12.33333,27.1231,13.31231,123.3232";
normalizare(string);
printf("%s",string);
}