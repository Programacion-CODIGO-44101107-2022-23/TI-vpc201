#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXELE 20

typedef struct
{
    double x;
    double y;
}tipopunto;

typedef tipopunto tipoarray[MAXELE];

int menu ();
void insertar (tipoarray a, int *n);
void listar (tipoarray a, int n);
void eliminar (tipoarray a, int *n);
void ecuacion (tipoarray a, int n);

int main ()
{
    int opcion, n;
    tipoarray a;

    n = 0;
    do
    {
        opcion = menu ();
        switch (opcion)
        {
        case 0: printf ("Fin del programa");
            break;
        case 1:
            insertar (a, &n);
            break;
        case 2:
            listar (a, n);
            break;
        case 3:
            eliminar (a, &n);
            break;
        case 4:
            ecuacion (a, n);
            break;
        default:
            printf ("\nOpcion no valida");
            break;
        }
    }while (opcion != 0);
    return 0;
}

int menu ()
{
    int opcion;

    printf ("\nMenu");
    printf ("\n1. Insertar punto");
    printf ("\n2. Imprimir listado");
    printf ("\n3. Eliminar punto");
    printf ("\n4. Ecuacion de la recta");
    printf ("\n0. Salir");
    printf ("\nIntroduce opcion: ");
    scanf (" %d", &opcion);
    return opcion;
}

void insertar (tipoarray a, int *n)
{
    if (*n == MAXELE)
        printf ("\nNo se pueden insertar mas puntos");
    else
    {
        printf ("\nIntroduce valor de x e y: ");
        scanf ("%lf %lf", &a[*n].x, &a[*n].y);
        *n = *n + 1;
    }
}

void listar (tipoarray a, int n)
{
    int i;

    if (n == 0)
        printf ("\nNo hay puntos");
    else
    {
        printf ("\nListado de puntos: ");
        for (i=0; i<n; i++)
        {
            printf ("\n%d.- (%.2lf, %.2lf)", i+1, a[i].x, a[i].y);
        }
    }
}

void eliminar (tipoarray a, int *n)
{
    int p, i;

    if (*n == 0)
        printf ("\nNo hay puntos");
    else
    {
        do
        {
            printf ("\nNumero punto: ");
            scanf (" %d", &p);
        }while (p<1 || p>*n);
        
        for (i=p; i<*n; i++)
        {
            a[i-1].x = a[i].x;
            a[i-1].y = a[i].y;
        }
        *n = *n - 1;
    }
}

void ecuacion (tipoarray a, int n)
{
    double sumx, sumy, sumxy, sumx2, sumy2, medx, medy, aa, b, r;
    int i;

    if (n == 0)
        printf ("\nNo hay puntos");
    else
    {
        if (n == 1)
            printf ("\nSolo hay 1 punto");
        else
        {
            sumx = 0;
            sumy = 0;
            sumxy = 0;
            sumx2 = 0;
            sumy2 = 0;
            for (i=0; i<n; i++)
            {
                sumx = sumx + a[i].x;
                sumy = sumy + a[i].y;
                sumxy = sumxy + a[i].x * a[i].y;
                sumx2 = sumx2 + a[i].x * a[i].x;
                sumy2 = sumy2 + a[i].y * a[i].y;
            }
            medx = sumx / n;
            medy = sumy / n;
            if (n * sumx2 - sumx * sumx == 0)
            {
                printf ("\nx = %.2lf", medx);
            }
            else
            {
                b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
                aa = medy - b * medx;
                printf ("\ny = %.2lf + %.2lf * x", aa, b);
            }
            if (n * sumx2 - sumx * sumx == 0 ||
                        n * sumy2 - sumy * sumy == 0)
                printf ("\nr indeterminado");
            else
            {
                r = (n * sumxy - sumx * sumy) /
                        sqrt((n * sumx2 - sumx * sumx) *
                             (n * sumy2 - sumy * sumy));
                printf ("\nr = %.2lf", r);
            }
        }
    }
}