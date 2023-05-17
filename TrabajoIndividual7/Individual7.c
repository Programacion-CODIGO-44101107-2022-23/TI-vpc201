#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>



int sumarcifras (int n);

int main()
{
    char c;


    int n, suma;


    do
    {
        system("cls");
        printf("Ejercicio 1\n");
        printf("====================================\n\n");


        do
        {
            printf ("\nIntroduce numero natural: ");
            scanf (" %d", &n);
        } while (n < 0);
        suma = sumarcifras (n);
        printf ("\nLa suma de las cifras es: %d", suma);
        





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}


int sumarcifras (int n)
{
    if (n == 0)
        return 0;
    else
        return n%10 + sumarcifras(n/10);
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
        /* Instrucciones del algoritmo */


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

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


double f1 (double x, double y);
double f2 (double x, double y);
double f3 (double x, double y);
double f4 (double x, double y);
void leerdatos (double *xmin, double *xmax, double *ymin, double *ymax, int *m, int *n);
double calcularvolumen (double (*f) (double x, double y), double xmin, double xmax, double ymin, double ymax, int m, int n);

int main()
{
    char c;

    int opcion, m, n;
    double xmin, xmax, ymin, ymax, resul;


    do
    {
        system("cls");
        printf("Ejercicio 6\n");
        printf("====================================\n\n");


        printf ("\nFunciones a utilizar: ");
        printf ("\n1. f(x,y) = log (x + 2y)");
        printf ("\n2. f(x,y) = x^2 + y^2");
        printf ("\n3. f(x,y) = x + y");
        printf ("\n4. f(x,y) = 1");
        do
        {
            printf ("\nIntroduce funcion (1,2,3,4): ");
            scanf (" %d", &opcion);
        }while (opcion < 1 || opcion > 4);

        leerdatos (&xmin, &xmax, &ymin, &ymax, &m, &n);

        switch (opcion)
        {
            case 1: resul = calcularvolumen (f1, xmin, xmax, ymin, ymax, m, n);
                    break;
            case 2: resul = calcularvolumen (f2, xmin, xmax, ymin, ymax, m, n);
                    break;
            case 3: resul = calcularvolumen (f3, xmin, xmax, ymin, ymax, m, n);
                    break;
            case 4: resul = calcularvolumen (f4, xmin, xmax, ymin, ymax, m, n);
                    break;
        }
        printf ("\nEl volumen total es: %.15lf", resul);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}


double f1 (double x, double y)
{
    return log(x + 2*y);
}

double f2 (double x, double y)
{
    return pow(x,2) + pow(y,2);
}

double f3 (double x, double y)
{
    return x + y;
}

double f4 (double x, double y)
{
    return 1;
}

void leerdatos (double *xmin, double *xmax, double *ymin, double *ymax, int *m, int *n)
{
    do
    {
        printf ("\nIntroduce x minima: ");
        scanf (" %lf", &*xmin);
        printf ("\nIntroduce x maxima: ");
        scanf (" %lf", &*xmax);
    } while (*xmin >= *xmax);
    do
    {
        printf ("\nIntroduce y minima: ");
        scanf (" %lf", &*ymin);
        printf ("\nIntroduce y maxima: ");
        scanf (" %lf", &*ymax);
    } while (*ymin >= *ymax);
    do
    {
        printf ("\nIntroduce numero de divisiones horizontales: ");
        scanf (" %d", &*m);
    } while (*m <= 0);
    do
    {
        printf ("\nIntroduce numero de divisiones verticales: ");
        scanf (" %d", &*n);
    } while (*n <= 0);
}

double calcularvolumen (double (*f) (double x, double y), double xmin, double xmax, double ymin, double ymax, int m, int n)
{
    double total, difx, dify, lx, ly, xi, yj, aij;
    int i, j;

    difx = xmax - xmin;
    dify = ymax - ymin;
    lx = difx / m;
    ly = dify / n;
    aij = lx * ly;
    total = 0;
    for (i=1; i<=m; i++)
    {
        xi = xmin + (i-1) * lx + lx/2;
        for (j=1; j<=n; j++)
        {
            yj = ymin + (j-1) * ly + ly/2;
            total = total + f(xi, yj) * aij;
        }
    }
    return total;
}
