#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


#define MAXPROTOTIPOS 3
#define MAXSESIONES 3
#define MAXVUELTAS 4


typedef double tipomatriz[MAXPROTOTIPOS][MAXSESIONES][MAXVUELTAS];


void leerdatos (tipomatriz m);
void mejorestiempos (tipomatriz m);
void tablaresumen (tipomatriz m);


int main(){
    char c;



    tipomatriz m;



    do{ system("cls");
        printf("Trabajo individual 11\n");
        printf("====================================\n\n");



        leerdatos (m);
        mejorestiempos (m);
        tablaresumen (m);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leerdatos (tipomatriz m)
{
    int i, j, k;

    printf ("\nTiempos empleados en cada vuelta de cada monoplaza durante cada sesion");
    for (i=0; i<MAXPROTOTIPOS; i++)
    {
        printf ("\nMonoplaza: %d", i+1);
        for (j=0; j<MAXSESIONES; j++)
        {
            printf ("\n   Sesion: %d", j+1);
            for (k=0; k<MAXVUELTAS; k++)
            {
                printf ("\n      Vuelta: %d  Introduce tiempo (0 si no la hizo): ", k+1);
                scanf (" %lf", &m[i][j][k]);
            }
        }
    }
}

void mejorestiempos (tipomatriz m)
{
    int i, j, k, sesion, vuelta;
    double min;

    printf ("\n\n");
    printf ("\nMEJORES TIEMPOS REGISTRADOS");
    printf ("\n===========================");
    printf ("\n");
    printf ("\nPrototipo  Tiempo minimo  No sesion  No vuelta");
    printf ("\n=========  =============  =========  =========");
    for (i=0; i<MAXPROTOTIPOS; i++)
    {
        min = 0;
        sesion = 0;
        vuelta = 0;
        for (j=0; j<MAXSESIONES; j++)
        {
            for (k=0; k<MAXVUELTAS; k++)
            {
                if (m[i][j][k] != 0)
                {
                    if (min == 0 || m[i][j][k] < min)
                    {
                        min = m[i][j][k];
                        sesion = j;
                        vuelta = k;
                    }
                }
            }
        }
        if (min == 0)
            printf ("\n%9d Sin datos registrados", i+1);
        else
            printf ("\n%9d  %12.2lf   %8d   %8d", i+1, min, sesion+1, vuelta+1);
    }
}

void tablaresumen (tipomatriz m)
{
    int i, j, k, contp, conts;
    double sumap, sumas, medp, meds;

    printf ("\n\n");
    printf ("\nTABLA RESUMEN TIEMPOS MEDIOS POR VUELTA");
    printf ("\n=======================================");
    printf ("\nPrototipo             No Sesion");
    printf ("\n          ");
    for (j=0; j<MAXSESIONES; j++)
    {
        printf ("     %5d", j+1);
    }
    printf ("     TOTAL");
    for (i=0; i<MAXPROTOTIPOS; i++)
    {
        printf ("\n%5d     ", i+1);
        sumap = 0;
        contp = 0;
        for (j=0; j<MAXSESIONES; j++)
        {
            sumas = 0;
            conts = 0;
            for (k=0; k<MAXVUELTAS; k++)
            {
                if (m[i][j][k] != 0)
                {
                    sumas = sumas + m[i][j][k];
                    conts++;
                }
            }
            sumap = sumap + sumas;
            contp = contp + conts;
            if (conts == 0)
                printf ("     S.D. ");
            else
            {
                meds = sumas / conts;
                printf ("     %.3lf", meds);
            }
        }
        if (contp == 0)
            printf ("     S.D. ");
        else
        {
            medp = sumap / contp;
            printf ("     %.3lf", medp);
        }
    }
}
