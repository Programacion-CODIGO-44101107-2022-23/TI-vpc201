#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void leernumeros (int *a, int *b);
int multiplicar (int a, int b);

int main()
{

    char c;


    int a, b, resul;


    do
    {
        system("cls");
        printf("Ejercicio 3\n");
        printf("====================================\n\n");


        leernumeros (&a, &b); 
        resul = multiplicar (a, b);
        printf ("\nEl resultado de %d * %d es %d", a, b, resul);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}


void leernumeros (int *a, int *b)
{
    do
    {
        printf ("\nIntroduce numero natural: ");
        scanf (" %d", &*a);
    } while (*a < 0);
    do
    {
        printf ("\nIntroduce otro numero natural: ");
        scanf (" %d", &*b);
    } while (*b < 0);
}

int multiplicar (int a, int b)
{
    if (a == 0)
        return 0;
    else 
    {
        if (a % 2 != 0)
            return b + multiplicar (a/2, b*2);
        else 
            return multiplicar (a/2, b*2);
    }
}