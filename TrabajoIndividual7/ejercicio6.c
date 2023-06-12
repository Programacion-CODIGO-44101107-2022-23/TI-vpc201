#include <stdio.h>
#include <stdlib.h>
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