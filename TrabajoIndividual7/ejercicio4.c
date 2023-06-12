#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void leerpunto (int *x, int *y);
int calcularcaminos (int ax, int ay, int bx, int by);

int main()
{

    char c;

    int ax, ay, bx, by, n;



    do
    {
        system("cls");
        printf("Ejercicio 4\n");
        printf("====================================\n\n");


        printf ("\nIntroduce coordenadas del primer punto: ");
        leerpunto (&ax, &ay); 
        printf ("\nIntroduce coordenadas del segundo punto: ");
        leerpunto (&bx, &by);
        n = calcularcaminos (ax, ay, bx, by); 
        printf ("\nEl numero de caminos NE es: %d", n);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}


void leerpunto (int *x, int *y)
{
    printf ("\nIntroduce coordenada x: ");
    scanf (" %d", &*x);
    printf ("\nIntroduce coordenada y: ");
    scanf (" %d", &*y);
}

int calcularcaminos (int ax, int ay, int bx, int by)
{

    if (ax > bx || ay > by)
        return 0;
    else 
    {
        if (ax == bx && ay == by)
            return 0;
        else 
        {
            if (ax == bx || ay == by)
                return 1;
            else 
                return calcularcaminos (ax+1, ay, bx, by) + calcularcaminos (ax, ay+1, bx, by);
        }
    }
}