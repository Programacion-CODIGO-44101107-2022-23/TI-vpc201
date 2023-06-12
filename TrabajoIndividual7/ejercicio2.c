#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void escribirbinario (int n);

int main()
{

    char c;

    int n;



    do
    {
        system("cls");
        printf("Ejercicio 2\n");
        printf("====================================\n\n");
      


        do
        {
            printf ("\nIntroduce numero natural: ");
            scanf (" %d", &n);
        } while (n < 0);
        printf ("\nEl número en binario es: ");
        escribirbinario (n);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}


void escribirbinario (int n)
{
    if (n == 0 || n == 1)
        printf ("%d", n);
    else 
    {
        escribirbinario (n / 2);
        printf ("%d", n%2);
    }
}