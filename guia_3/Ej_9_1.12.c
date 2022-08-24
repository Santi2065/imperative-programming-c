#include <stdio.h>
int main(void)
{
    int c, estado;
    estado = 0;
    while ((c = getchar()) != EOF)
        switch (estado)
        {
        case 1:
            if (c == ' ' || c == '\n' || c == '\t')
            {
                putchar('\n');
                estado = 0;
            }
            else
                putchar(c);
            break;
        case 0:
            if (c != ' ' && c != '\n' && c != '\t')
            {
                estado = 1;
                putchar(c);
            }
            break;
        }
    return 0;
}