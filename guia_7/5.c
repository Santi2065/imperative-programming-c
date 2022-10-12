#include <stdio.h>
#include <string.h>
void separaCursos(char nombre[6][8],const char *curso, char cursog[6][8], char cursoh[6][8]){
    int indG=0;
    int indH=0;
    /* Asumo que en el string curso hay solo curso G y H,
    ** y que no escribe otro curso.
    */
    for(int i=0;nombre[i][0]!='\0';i++){
        if(curso[i]=='G')
            strcpy(cursog[indG++],nombre[i]);
        else
            strcpy(cursoh[indH++],nombre[i]);
    }
    cursog[indG][0]=0;
    cursoh[indH][0]=0;
}

/*
int main(void){
char curso[6]={"GGHG0"};
char nombre[6][8]={"Juan","Ricarda","Erica","Malena",""};
char cursoH[6][8]={0};
char cursoG[6][8]={0};
cursos(curso,nombre,cursoG,cursoH);
printf("%s\n","El curso G:");
for(int i=0;cursoG[i][0]!=0;i++)
    printf("%s\n",cursoG[i]);
printf("%s\n","El curso H:");
for(int i=0;cursoH[i][0]!=0;i++)
    printf("%s\n",cursoH[i]);
}
*/
