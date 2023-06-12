#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



void leerdatos (double *a, double *b, double *base);
double calculararea (double (*f) (double x), double a, double b, double base);
double f1 (double x);
double f2 (double x);
double f3 (double x);

int main()
{

    char c;
    int opcion;
    double a, b, base, areatotal;



    do
    {
        system("cls");
        printf("Ejercicio 5\n");
        printf("====================================\n\n");


        printf ("\nFunciones a utilizar: ");
        printf ("\n1. f(x) = x^3 - 3x^2 + 5");
        printf ("\n2. f(x) = exp (-x^2)");
        printf ("\n3. f(x) = seno(x) * exp(-x)");
        do
        {
            printf ("\nIntroduce función (1,2,3): ");
            scanf (" %d", &opcion);
        }while (opcion < 1 || opcion > 3);
        leerdatos (&a, &b, &base); 

        switch (opcion)
        {
            case 1: areatotal = calculararea (f1, a, b, base);
                    break;
            case 2: areatotal = calculararea (f2, a, b, base);
                    break;
            case 3: areatotal = calculararea (f3, a, b, base);
                    break;
        }
        printf ("\nEl area total es: %.6lf", areatotal);
        





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}

void leerdatos (double *a, double *b, double *base)
{
    printf ("\nIntroduce el punto inicial: ");
    scanf (" %lf", &*a);
    do 
    {
        printf ("\nIntroduce el punto final (mayor que el inicial): ");
        scanf (" %lf", &*b);
    }while (*b <= *a);
    do
    {
        printf ("\nIntroduce la base (numero positivo): ");
        scanf (" %lf", &*base);
    }while (*base <= 0);
}

double calculararea (double (*f) (double x), double a, double b, double base)
{
    double areatotal, izq, der, hizq, hder, area;
    char fin;

    areatotal = 0;
    izq = a;
    fin = 'n';
    while (fin == 'n')
    {
        der = izq + base;
        if (der > b)
            fin = 's';
        else 
        {
            hizq = f(izq);
            hder = f(der);
            area = base * (hizq + hder) / 2;
            areatotal = areatotal + area;
            izq = der;
        }
    }
    der = b;
    base = der - izq;
    hizq = f(izq);
    hder = f(der);
    area = base * (hizq + hder) / 2;
    areatotal = areatotal + area;
    return areatotal;
}

double f1 (double x)
{
    return pow(x,3) - 3*pow(x,2) + 5;
}

double f2 (double x)
{
    return exp (- pow(x,2));
}

double f3 (double x)
{
    return sin (x) * exp (-x);
}