#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXEL 100
#define TAMAMAX 25

typedef int tipotabla[MAXEL][MAXEL];

typedef struct
{
    int nfil;
    int ncol;
    double tama;
    tipotabla t;
}tipodatos;

typedef struct
{
    int col;
    int fil;
    int ancho; 
    int largo; 
}tipopieza;

typedef char cadena30[31];


void leerdatos (cadena30 nomcfg, cadena30 nomdat,
                tipodatos *datos);
char haypiezas (tipodatos datos);
void cogermayorpieza (tipodatos datos, tipopieza *pieza);
void eliminarpieza (tipodatos *datos, tipopieza pieza);


int main ()
{
    cadena30 nomcfg, nomdat, nomext;
    tipodatos datos;
    FILE *f;
    tipopieza pieza;

    strcpy (nomcfg, "pieza.cfg");
    strcpy (nomdat, "pieza.dat");
    strcpy (nomext, "pieza.ext");
    leerdatos (nomcfg, nomdat, &datos);
    f = fopen (nomext, "w");
    while (haypiezas (datos) == 's')
    {
        cogermayorpieza (datos, &pieza);
        eliminarpieza (&datos, pieza);
        fprintf (f, "%d %d %d %d\n", pieza.col, pieza.fil,
                 pieza.ancho, pieza.largo);
    }
    fclose();
}


void leerdatos (cadena30 nomcfg, cadena30 nomdat,
                tipodatos *datos)
{
    FILE *f1, *f2;
    int i, j;

    f1 = fopen (nomcfg, "r");
    fscanf (f, "%d %d %lf", &datos->nfil, &datos->ncol,
            &datos->tama);
    fclose (f1);
    f2 = fopen (nomdat, "r");
    for (i=0; i<datos->nfil; i++)
    {
        for (j=0; j<datos->ncol; j++)
        {
            fscanf (f, "%d", &datos->t[i][j]);
        }
    }
    fclose (f2);
}

char haypiezas (tipodatos datos)
{
    int i, j;
    char hay1;

    hay1 = 'n';
    i = 0;
    while (i < datos.nfil && hay1 == 'n')
    {
        j = 0;
        while (j < datos.ncol && hay1 == 'n')
        {
            if (datos.t[i][j] == 1)
                hay1 = 's';
            j++;
        }
        i++;
    }
    return hay1;
}

void cogermayorpieza (tipodatos datos, tipopieza *pieza)
{

}

void eliminarpieza (tipodatos *datos, tipopieza pieza)
{

}