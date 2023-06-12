#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct
{
    int dia;
    int mes;
    int anio;
}tipofecha;

typedef tipofecha tipovector[MAX];

void generaraleatorio (tipovector v);
void escribirvector (tipovector v);
void ordenarvector (tipovector v);
void invertirvector (tipovector v);

int main ()
{
    tipovector v;
    time_t t;

    srand((unsigned) time(&t));
    generaraleatorio (v);
    printf ("\nVector original: ");
    escribirvector (v);
    ordenarvector (v);
    printf ("\nVector ordenado: ");
    escribirvector (v);
    invertirvector (v);
    printf ("\nVector orden inverso: ");
    escribirvector (v);
}

void generaraleatorio (tipovector v)
{
    int i;

    for (i=0; i<MAX; i++)
    {
        
        v[i].dia = (int) (rand() % 31 + 1);
        
        v[i].mes = (int) (rand() % 12 + 1);
        
        v[i].anio = (int) (rand() % 7 + 2000);
    }
}

void escribirvector (tipovector v)
{
    int i;

    printf ("\n");
    for (i=0; i<MAX; i++)
    {
        printf ("%d-%d-%d\t", v[i].dia, v[i].mes, v[i].anio);
    }
    printf ("\n");
}

void ordenarvector (tipovector v)
{
    int i, j;
    tipofecha aux;

    for (i=1; i<MAX; i++)
    {
        for (j=0; j<MAX-i; j++)
        {
            if (v[j].anio > v[j+1].anio ||
                (v[j].anio == v[j+1].anio && v[j].mes > v[j+1].mes) ||
                (v[j].anio == v[j+1].anio && v[j].mes == v[j+1].mes
                    && v[j].dia > v[j+1].dia))
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void invertirvector (tipovector v)
{
    int i, j;
    tipofecha aux;

    i = 0;
    j = MAX - 1;
    while (i < j)
    {
        aux = v[j];
        v[j] = v[i];
        v[i] = aux;
        i++;
        j--;
    }
}