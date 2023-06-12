#include <stdio.h>
#include <stdlib.h>
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

