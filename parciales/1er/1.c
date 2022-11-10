#include <stdio.h>
void normalizar(char * s)
{
    int count=0,dim=0,aux=0;
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='.')
        {
            s[dim++]=s[i++];
            while(s[i]!=','&&s[i]!=0)
            {
                if(count<2)
                {
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

int main(void){
char string[] = "12.33333,27.1231,13.31231,123.3232";
normalizar(string);
printf("%s",string);
}