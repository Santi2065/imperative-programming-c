#include <stdio.h> 
int
main(void)
{
    char v[][6]={"Uno","Dos","Tres"};
    v[0] = v[2]+1;
    printf("%s\n",v[0]);
    return 0;
}