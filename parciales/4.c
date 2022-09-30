#define ES_VOCAL(a) a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'
#define TO_LOWER(a) a>'Z'?a:(a+('a'-'A'))
#include <stdio.h>
void main(){
    printf("%c\n",TO_LOWER('a'));
}