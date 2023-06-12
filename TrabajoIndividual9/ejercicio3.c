#include <stdio.h>
#include <stdlib.h>
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
