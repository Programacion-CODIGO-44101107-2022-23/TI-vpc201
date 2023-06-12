#include <stdio.h>
#include <stdlib.h>
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

