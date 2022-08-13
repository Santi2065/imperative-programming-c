#include <stdio.h>
int main(void){
  char a, b, num, ahex, bhex;
  a = getchar();
  b = getchar();
  if(a >='0' && a <= '9' && b >= '0' && b <= '9'){
    ahex = ((a/16)*10)+(a%16);
    bhex = ((b/16)*10)+(b%16);
    a = a - '0';
    b = b - '0';
    num = (a*10)+b;
  }
    printf("%d %h %h",num, ahex, bhex);
return 0;
}
