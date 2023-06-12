#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXMEDIDAS 10

typedef struct
{
    float temp;
    float pres;
    float vien;
    float hume;
}tipomedida;

typedef tipomedida tipovector[MAXMEDIDAS];

typedef struct
{
    int n;
    tipovector v;
}tipodatos;

void insertarmedida (tipodatos *datos, tipomedida med);
void escribirmedida (tipomedida med);
void escribirevoluciontemperatura (tipodatos datos);
float calcularmaximo (tipodatos datos);
float calcularminimo (tipodatos datos);
float calcularmedia (tipodatos datos);
void escribirevolucionpresion (tipodatos datos);

int main ()
{
    char nombre[30];
    FILE *f;
    tipodatos datos;
    tipomedida med;
    int t;
    time_t t1, t2;

    strcpy (nombre, "meteoro.txt");
    datos.n = 0;
    t = 0;
    f = fopen (nombre, "r");
    if (f == NULL)
        printf ("\nNo hay datos de medidas");
    else
    {
        fscanf (f, "%f %f %f %f", &med.temp, &med.pres,
                    &med.vien, &med.hume);
        while ( ! feof(f))
        {
            insertarmedida (&datos, med);
            printf ("\n\nt = %d sg.", t);
            escribirmedida (med);
            escribirevoluciontemperatura (datos);
            escribirevolucionpresion (datos);
            t = t + 25;
            t1 = time(NULL);
            while(difftime(time(NULL), t1)<1);
            fscanf (f, "%f %f %f %f", &med.temp, &med.pres,
                    &med.vien, &med.hume);
        }
        fclose (f);
    }
}

void insertarmedida (tipodatos *datos, tipomedida med)
{
    int i;

    if (datos->n < MAXMEDIDAS)
    {
        datos->v[datos->n] = med;
        datos->n ++;
    }
    else
    {
        
        for (i=0; i<datos->n-1; i++)
        {
            datos->v[i] = datos->v[i+1];
        }
        datos->v[datos->n-1] = med;
    }
}

void escribirmedida (tipomedida med)
{
    time_t t;

    t = time(NULL);
    printf ("\n      			ESTACION METEOROLOGICA");
    printf ("\n============================================");
    printf ("\n%s",ctime(&t));
    printf ("\n============================================");
    printf ("\nTemperatura (ºc):                   %6.2f", med.temp);
    printf ("\nPresion atmosferica (mm de Hg):     %6.2f", med.pres);
    printf ("\nVelocidad del viento (m/sg):        %6.2f", med.vien);
    printf ("\nHumedad relativa (%%):               %6.2f", med.hume);
}

void escribirevoluciontemperatura (tipodatos datos)
{
    float max, min, med;

    max = calcularmaximo (datos);
    min = calcularminimo (datos);
    med = calcularmedia (datos);
    printf ("\n============================================");
    printf ("\nEvolucion de la temperatura:");
    printf ("\n	Temperatura maxima:         %6.2f", max);
    printf ("\n	Temperatura minima:         %6.2f", min);
    printf ("\n	Temperatura media (10 u.l.):%6.2f", med);
}


float calcularmaximo (tipodatos datos)
{
    int i;
    float max;

    max = datos.v[0].temp;
    for (i=1; i<datos.n; i++)
    {
        if (datos.v[i].temp > max)
        {
            max = datos.v[i].temp;
        }
    }
    return max;
}

float calcularminimo (tipodatos datos)
{
    int i;
    float min;

    min = datos.v[0].temp;
    for (i=1; i<datos.n; i++)
    {
        if (datos.v[i].temp < min)
        {
            min = datos.v[i].temp;
        }
    }
    return min;
}

float calcularmedia (tipodatos datos)
{
    int i;
    float suma;

    suma = 0;
    for (i=0; i<datos.n; i++)
    {
        suma = suma + datos.v[i].temp;
    }
    return suma / datos.n;
}

void escribirevolucionpresion (tipodatos datos)
{


    printf ("\n============================================");
    printf ("\nEvolucion de la presion atmosferica:");
    if (datos.n == 1)
        printf ("\n      Datos de presion insuficientes");
    else
    {
        if (datos.v[datos.n-2].pres < datos.v[datos.n-1].pres)
            printf ("\n      La presion esta aumentando");
        else
        {
            if (datos.v[datos.n-2].pres > datos.v[datos.n-1].pres)
                printf ("\n      La presion esta disminuyendo");
            else
                printf ("\n      La presion se mantiene estacionaria");
        }
    }
}