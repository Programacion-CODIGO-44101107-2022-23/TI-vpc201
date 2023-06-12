#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 50
typedef char cadena50[N+1];

void dejaralfabeticos (cadena50 cad, int *longitud);

int main ()
{
    cadena50 cad;
    int longitud;

    printf ("\nIntroduce cadena: ");
    gets (cad);
    longitud = strlen(cad);
    dejaralfabeticos (cad, &longitud);
    printf ("\nLa cadena solo alfabetica es: %s", cad);
}

void dejaralfabeticos (cadena50 cad, int *longitud)
{
    int i, j;

    i = 0;
    while (i < *longitud)
    {
        if (isalpha (cad[i]))
            i++;
        else
        {
            for (j=i; j<*longitud; j++)
                cad[j] = cad[j+1];
            (*longitud)--;
        }
    }
}

