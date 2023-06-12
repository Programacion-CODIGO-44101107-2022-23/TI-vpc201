#include <stdio.h>

#define N 50
typedef char cadena50[N+1];

void leer_cadena(cadena50 cad);
void imprimirpalabras (cadena50 cad);
int longitudcadena (cadena50 cad);

int main ()
{
    cadena50 cad;

    printf ("\nIntroduce cadena de como maximo %d caracteres (ENTER para terminar):\n", N);
    leer_cadena (cad);
    imprimirpalabras (cad);
}

void leer_cadena(cadena50 cad)
{
    int i,fin;
    char c;

    i=0;
    fin=0;
    while((i<N)&&(!fin))
    {
        c=getch();
        switch(c){
        case '\r': fin=1;
                   printf("\n");
                   break;
        case '\b': if (i>0){
                     --i;
                     printf("\b \b");
                   }
                   break;
        default:   cad[i]=c;
                   ++i;
                   printf("%c",c);
                   break;
        }
    }
    cad[i]='\0';
    if (i==N)
        printf("\n");
}

void imprimirpalabras (cadena50 cad)
{
    int n, i, j;
    cadena50 palabra;

    printf ("\nLas palabras son:\n");
    n = longitudcadena (cad);
    i = 0;
    while (i < n)
    {
        j = 0;
        while (i<n && cad[i]!=' ')
        {
            palabra[j] = cad[i];
            i++;
            j++;
        }
        palabra[j] = '\0';
        dejaralfabeticos(palabra);
        if (longitudcadena(palabra) != 0)
            printf ("\n%s", palabra);
        i++;
    }
}

int longitudcadena (cadena50 cad)
{
    int i;

    i = 0;
    while (cad[i] != '\0')
        i++;
    return i;
}


void dejaralfabeticos (cadena50 cad)
{
    int i, j, n;

    i = 0;
    n = longitudcadena (cad);
    while (i < n)
    {
        if ((cad[i]>='a' && cad[i]<='z') ||
                (cad[i]>='A' && cad[i]<='Z'))
            i++;
        else
        {
            for (j=i; j<n; j++)
                cad[j] = cad[j+1];
            (n)--;
        }
    }
}