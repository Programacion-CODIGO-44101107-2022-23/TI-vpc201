#include <stdio.h>
#include <string.h>

#define N 50

typedef char cadena50[N+1];

void invertir (cadena50 cad1, cadena50 cad2);

int main ()
{
    cadena50 cad1, cad2;

    printf ("\nIntroduce cadena de caracteres: ");
    gets (cad1);
    invertir (cad1, cad2); 
    printf ("\nLa cadena invertida es: %s", cad2);
}

void invertir (cadena50 cad1, cadena50 cad2)
{
    int i, j;

    j = 0;
    for (i=strlen(cad1)-1; i>=0; i--)
    {
        cad2[j] = cad1[i];
        j++;
    }
    cad2[j] = '\0';
}
