#include <stdio.h>
int main(void){
  char a,b;
  a = getchar();
  b = getchar();
  if(a<b)
    printf("%c\n", b);
  else
    printf("%c\n", a);
  return 0;
}
