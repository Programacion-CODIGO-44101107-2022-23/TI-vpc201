#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


#define PI 3.14159





void leerlongitudes (double *la, double *lb);
void leerpunto (double *x, double *y);
void calculodesplazamiento (double alfa, double beta, double nuevoalfa, double nuevobeta,
                            double *despalfa, double *despbeta);
char comprobaraccesible (double x, double y, double la, double lb);
void calcularangulos (double x, double y, double la, double lb,
                      double *nuevoalfa, double *nuevobeta);

int main(){
    char c;


    double la, lb, alfa, beta, x, y, nuevoalfa, nuevobeta, despalfa, despbeta;
    char fin, acceso;




    do{ system("cls");
        printf("Ejercicio 1\n");
        printf("====================================\n\n");



        leerlongitudes (&la, &lb);
        alfa = 0;
        beta = 0;
        fin = 'n';
        while (fin == 'n')
        {
            leerpunto (&x, &y);
            if (x == 0 && y == 0)
            {
                nuevoalfa = 0;
                nuevobeta = 0;
                calculodesplazamiento (alfa, beta, nuevoalfa, nuevobeta,
                                       &despalfa, &despbeta);
                printf ("\nDesplazamiento angular: (%.2lf, %.2lf)",
                        despalfa, despbeta);
                printf ("\nPosicion angular final: (%.2lf, %.2lf)",
                        nuevoalfa, nuevobeta);
                fin = 's';
            }
            else
            {
                acceso = comprobaraccesible (x, y, la, lb);
                if (acceso == 'n')
                {
                    printf ("\nPosicion inalcanzable");
                    printf ("\nPosicion angular final: (%.2lf, %.2lf)", alfa, beta);
                }
                else
                {
                    calcularangulos (x, y, la, lb, &nuevoalfa, &nuevobeta);
                    calculodesplazamiento (alfa, beta, nuevoalfa, nuevobeta,
                                       &despalfa, &despbeta);
                    printf ("\nDesplazamiento angular: (%.2lf, %.2lf)",
                            despalfa, despbeta);
                    printf ("\nPosicion angular final: (%.2lf, %.2lf)",
                            nuevoalfa, nuevobeta);
                    alfa = nuevoalfa;
                    beta = nuevobeta;
                }
            }
        }







        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leerlongitudes (double *la, double *lb)
{
    printf ("\nIntroduce longitud del antebrazo: ");
    scanf (" %lf", &*la);
    printf ("\nIntroduce longitud del brazo: ");
    scanf (" %lf", &*lb);
}

void leerpunto (double *x, double *y)
{
    printf ("\nPara terminar introduce el punto (0,0)");
    printf ("\nIntroduce coordenada x: ");
    scanf (" %lf", &*x);
    printf ("\nIntroduce coordenada y: ");
    scanf (" %lf", &*y);
}

void calculodesplazamiento (double alfa, double beta, double nuevoalfa, double nuevobeta,
                            double *despalfa, double *despbeta)
{
    *despalfa = nuevoalfa - alfa;
    if (*despalfa > 180)
        *despalfa = *despalfa - 360;
    else
    {
        if (*despalfa < -180)
            *despalfa = *despalfa + 360;
    }
    *despbeta = nuevobeta - beta;
    if (*despbeta > 180)
        *despbeta = *despbeta - 360;
    else
    {
        if (*despbeta < -180)
            *despbeta = *despbeta + 360;
    }
}

char comprobaraccesible (double x, double y, double la, double lb)
{
    double d, r;
    char acceso;

    d = sqrt (x*x + y*y);
    r = sqrt (la*la + lb*lb - sqrt(3)*la*lb);
    if (d < r || d > la+lb)
        acceso = 'n';
    else
        acceso = 's';
    return acceso;
}

void calcularangulos (double x, double y, double la, double lb,
                      double *nuevoalfa, double *nuevobeta)
{
    double d, tita, alfa1, beta180;

    d = sqrt (x*x + y*y);
    tita = acos (x / d);
    alfa1 = acos ((d*d + la*la - lb*lb) / (2*d*la));
    *nuevoalfa = tita - alfa1;
    *nuevoalfa = *nuevoalfa * 180 / PI;
    if (*nuevoalfa < 0)
        *nuevoalfa = *nuevoalfa + 360;
    beta180 = acos ((la*la + lb*lb - d*d) / (2*la*lb));
    beta180 = beta180 * 180 / PI;
    *nuevobeta = 180 - beta180;
    if (*nuevobeta < 0)
        *nuevobeta = *nuevobeta + 360;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


#define PI 3.14159


double calcularmaximaelongacion (double errormax, double precision);
double calcularerror (double elon, int numter);
void escribirtablaerrores (double elonmax, double precision);

int main(){
    char c;



    double errormax, precision, elonmax;



    do{ system("cls");
        printf("Ejercicio 2\n");
        printf("====================================\n\n");



        printf ("\nIntroduce el error maximo permitido: ");
        scanf (" %lf", &errormax);
        printf ("\nIntroduce la precision (en grados): ");
        scanf (" %lf", &precision);
        elonmax = calcularmaximaelongacion (errormax, precision);
        printf ("\nError relativo maximo: %lf (%lf %%)", errormax, errormax*100);
        printf ("\nPrecision: %.1lf (grados)", precision);
        printf ("\n\nElongacion maxima: %.3lf grados", elonmax);
        escribirtablaerrores (elonmax, precision);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

double calcularmaximaelongacion (double errormax, double precision)
{
    double elon, error;
    char fin;

    fin = 'n';
    elon = 0;
    while (fin == 'n')
    {
        error = calcularerror (elon, 100);
        if (error > errormax)
        {
            fin = 's';
            elon = elon - precision;
        }
        else
            elon = elon + precision;
    }
    return elon;
}

double calcularerror (double elon, int numter)
{
    double rad, suma, prod;
    int i, j;

    rad = elon * PI / 180;
    suma = 0;
    for (i=1; i<=numter; i++)
    {
        prod = 1;
        for (j=1; j<=i; j++)
        {
            prod = prod * (pow(2*j-1, 2) / pow(2*j, 2));
        }
        suma = suma + prod * pow (sin(rad/2), 2*i);
    }
    return suma;
}

void escribirtablaerrores (double elonmax, double precision)
{
    double elon, er1, er10, er100, er1000;

    printf ("\n\n\n");
    printf ("\n            Tabla de errores relativos");
    printf ("\n                        Numero de t�rminos de la serie");
    printf ("\nElongacion(Grados)      1                  10                 100                1000");
    for (elon=0; elon<=elonmax; elon=elon+precision)
    {
        er1 = calcularerror(elon, 1);
        er10 = calcularerror(elon, 10);
        er100 = calcularerror(elon, 100);
        er1000 = calcularerror(elon, 1000);
        printf("\n%.3lf   %.15lf   %.15lf   %.15lf   %.15lf", elon, er1, er10, er100, er1000);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>



void leerdatos (int *nf, int *nc, int *sep);
void escribirpatron (int nf, int nc, int sep);
void escribirpatron2 (int nf, int nc, int sep);


int main(){
    char c;



    int nf, nc, sep;



    do{ system("cls");
        printf("Ejercicio 3\n");
        printf("====================================\n\n");



        leerdatos (&nf, &nc, &sep);
        escribirpatron (nf, nc, sep);
        printf ("\n------------------------------\n");
        escribirpatron2 (nf, nc, sep);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leerdatos (int *nf, int *nc, int *sep)
{
    printf ("\nIntroduce numero de filas: ");
    scanf (" %d", &*nf);
    printf ("\nIntroduce numero de columnas: ");
    scanf (" %d", &*nc);
    printf ("\nIntroduce numero de separacion: ");
    scanf (" %d", &*sep);
}

void escribirpatron (int nf, int nc, int sep)
{
    int i, j, espdel, esp;

    espdel = 0;
    for (i=1; i<=nf; i++)
    {
        esp = espdel;
        for (j=1; j<=nc; j++)
        {
            if (esp == 0)
                printf ("*");
            else
                printf (" ");
            esp--;
            if (esp < 0)
                esp = sep;
        }
        printf ("\n");
        espdel++;
        if (espdel > sep)
            espdel = 0;
    }
}


void escribirpatron2 (int nf, int nc, int sep)
{
    int i, j, espdel, k;

    espdel = 0;
    for (i=1; i<=nf; i++)
    {
        for (j=1; j<=espdel; j++)
            printf (" ");
        while (j <= nc)
        {
            printf ("*");
            for (k=1; k<=sep; k++)
                printf (" ");
            j = j + 1 + sep;
        }
        printf ("\n");
        espdel++;
        if (espdel > sep)
            espdel = 0;
    }
}
