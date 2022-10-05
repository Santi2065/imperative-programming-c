#include <stdio.h>
#include <ctype.h>
 
#include <stdio.h>

void
upper(char * s)
{
      while ( *s = toupper(*s))
         s++;
}

int
main(void)
{
    char *s = "abcdef";
    upper(s);
    printf("%s\n",s);
    return 0;
}  