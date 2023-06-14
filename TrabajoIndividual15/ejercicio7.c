#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


double f1 (double x);
double f2 (double x);
void leerdatos (double *a, double *b, int *ciclos);
double montecarlo (double (*f) (double x),
                   double a, double b, int ciclos);

int main()
{
    char c;


    time_t t;
    double a, b, area;
    int ciclos, opcion;


    srand ((unsigned) time(&t));
    do{
        system("cls");
        printf("Ejercicio 7\n");
        printf("====================================\n\n");


        leerdatos (&a, &b, &ciclos);
        do
        {
            printf ("\nFunciones:");
            printf ("\n1. f(x) = x^3 -3x^2 +5");
            printf ("\n2. f(x) = exp(-x^2)");
            printf ("\nQue funcion quieres utilizar: ");
            scanf (" %d", &opcion);
        }while (opcion < 1 || opcion > 2);
        switch (opcion)
        {
        case 1:
            area = montecarlo (f1, a, b, ciclos);
            break;
        case 2:
            area = montecarlo (f2, a, b, ciclos);
            break;
        }
        printf ("\nEl area es: %.6lf", area);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

double f1 (double x)
{
    return x*x*x - 3*x*x +5;
}
double f2 (double x)
{
    return exp (-x*x);
}

void leerdatos (double *a, double *b, int *ciclos)
{
    do
    {
        printf ("\nIntroduce valores del intervalo: ");
        scanf (" %lf %lf", &*a, &*b);
    }while (*a >= *b);
    do
    {
        printf ("\nIntroduce numero de ciclos a ejecutar: ");
        scanf (" %d", &*ciclos);
    }while (*ciclos <= 0);
}

double montecarlo (double (*f) (double x),
                   double a, double b, int ciclos)
{
    int cont, i;
    double tama, rx, y, ymax, fraccion, area, ry;

    tama = b - a;
    cont = 0;
    ymax = 0;
    for (i=1; i<=ciclos; i++)
    {
        rx = (double)rand()/RAND_MAX * tama + a;
        y = f(rx);
        if (y > ymax)
            ymax = y;
        ry = (double)rand()/RAND_MAX * ymax;
        if (ry <= y)
            cont++;
    }
    fraccion = (double) cont / ciclos;
    area = fraccion * ymax * tama;
    return area;
}