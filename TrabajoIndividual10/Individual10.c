#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


#define MAXPUNTOS 5


typedef double tipoarray[MAXPUNTOS];


int menu ();
void insertarpunto (tipoarray x, tipoarray y, int *numpuntos);
void listarpuntos (tipoarray x, tipoarray y, int numpuntos);
void eliminarpunto (tipoarray x, tipoarray y, int *numpuntos);
void rectaregresion (tipoarray x, tipoarray y, int numpuntos);
double mediavector (tipoarray a, int numpuntos);
double calcularb (tipoarray x, tipoarray y, int numpuntos);
double calcularcoeficiente (tipoarray x, tipoarray y, int numpuntos);

int main(){

    tipoarray x, y;
    int numpuntos, opcion;



    numpuntos = 0;
    do{

        opcion = menu ();
        switch (opcion)
        {
        case 1:
            insertarpunto (x, y, &numpuntos);
            break;
        case 2:
            listarpuntos (x, y, numpuntos);
            break;
        case 3:
            eliminarpunto (x, y, &numpuntos);
            break;
        case 4:
            rectaregresion (x, y, numpuntos);
            break;
        case 0:
            printf ("\n\nSE ACABO");
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

    printf ("\n\nMENU PRINCIPAL");
    printf ("\n1. Insertar un nuevo punto experimental");
    printf ("\n2. Imprimir un listado de puntos");
    printf ("\n3. Eliminar un punto");
    printf ("\n4. Imprimir la ecuacion de la recta y coeficiente de correlacion");
    printf ("\n0. Finalizar el programa");
    printf ("\nIntroduce opcion: ");
    scanf (" %d", &opcion);
    return opcion;
}

void insertarpunto (tipoarray x, tipoarray y, int *numpuntos)
{
    if (*numpuntos == MAXPUNTOS)
        printf ("\nNo se pueden insertar mas puntos");
    else
    {
        printf ("\nIntroduce coordenadas x e y del nuevo punto: ");
        scanf (" %lf %lf", &x[*numpuntos], &y[*numpuntos]);
        *numpuntos = *numpuntos + 1;
    }
}

void listarpuntos (tipoarray x, tipoarray y, int numpuntos)
{
    int i;

    if (numpuntos == 0)
        printf ("\nNo hay puntos que listar");
    else
    {
        printf ("\n\nListado de puntos: ");
        for (i=0; i<numpuntos; i++)
        {
            printf ("\n%d.- (%.2lf, %.2lf)", i+1, x[i], y[i]);
        }
    }
}

void eliminarpunto (tipoarray x, tipoarray y, int *numpuntos)
{
    int n, i;

    if (*numpuntos == 0)
        printf ("\nNo hay puntos a eliminar");
    else
    {
        do
        {
            printf ("\nIntroduce el numero de punto a eliminar: ");
            scanf (" %d", &n);
        }while (n < 1 || n > *numpuntos);
        for (i=n; i<*numpuntos; i++)
        {
            x[i-1] = x[i];
            y[i-1] = y[i];
        }
        (*numpuntos)--;
    }
}

void rectaregresion (tipoarray x, tipoarray y, int numpuntos)
{
    double xmed, ymed, a, b, r;

    if (numpuntos == 0)
        printf ("\nNingun punto introducido");
    else
    {
        if (numpuntos == 1)
            printf ("\nSolo hay un punto experimental");
        else
        {
            xmed = mediavector (x, numpuntos);
            ymed = mediavector (y, numpuntos);
            b = calcularb (x, y, numpuntos);
            if (b == 0)
            {
                printf ("\nx = %.2lf", xmed);
                printf ("\nr indeterminado");
            }
            else
            {
                a = ymed - b * xmed;
                printf ("\ny = %.2lf + %.2lf * x", a, b);
                r = calcularcoeficiente (x, y, numpuntos);
                printf ("\nr = %.2lf", r);
            }
        }
    }
}


double mediavector (tipoarray a, int numpuntos)
{
    int i;
    double sum;

    sum = 0;
    for (i=0; i<numpuntos; i++)
    {
        sum = sum + a[i];
    }
    return sum / numpuntos;
}

double calcularb (tipoarray x, tipoarray y, int numpuntos)
{
    int i;
    double sumxy, sumx, sumy, sumx2;

    sumxy = 0;
    sumx = 0;
    sumy = 0;
    sumx2 = 0;
    for (i=0; i<numpuntos; i++)
    {
        sumxy = sumxy + x[i]*y[i];
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumx2 = sumx2 + x[i]*x[i];
    }
    if (numpuntos * sumx2 - sumx * sumx == 0)
        return 0;
    else
        return (numpuntos * sumxy - sumx * sumy) / (numpuntos * sumx2 - sumx * sumx);
}

double calcularcoeficiente (tipoarray x, tipoarray y, int numpuntos)
{
    int i;
    double sumxy, sumx, sumy, sumx2, sumy2;

    sumxy = 0;
    sumx = 0;
    sumy = 0;
    sumx2 = 0;
    sumy2 = 0;
    for (i=0; i<numpuntos; i++)
    {
        sumxy = sumxy + x[i]*y[i];
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumx2 = sumx2 + x[i]*x[i];
        sumy2 = sumy2 + y[i]*y[i];
    }
    return (numpuntos * sumxy - sumx * sumy) /
            sqrt((numpuntos * sumx2 - sumx * sumx) * (numpuntos * sumy2 - sumy * sumy));
}
