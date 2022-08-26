#include <stdio.h>
int esPrimo(){
    
}
int numerosAmigos(int a,int b){
    int suma_a=0,suma_b=0;
    for (int i=1;i<a;i++){
        if(a%i==0)
            suma_a+=i;
    }
    for (int x=1;x<b;x++){
        if(b%x==0)
            suma_b+=x;
    }
    if(suma_a==b&&suma_b==a)
    return 1;
    else
    return 0;
}
int main(void){
    printf("%s son numeros amigos",numerosAmigos(220,284)?"":"no");
}
//modulariza pelotudo