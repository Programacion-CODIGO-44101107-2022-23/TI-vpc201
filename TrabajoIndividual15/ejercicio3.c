#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXECUACIONES 10
#define MAXINCOGNITAS 10

typedef int tipotabla[MAXECUACIONES][MAXINCOGNITAS+1];

typedef struct
{
    int numecu;
    int numinc;
    tipotabla t;
} tiposistema;

typedef int tiposolucion[MAXINCOGNITAS];


void leersistema (tiposistema *sis);
void resolversistema (tiposistema sis, tiposolucion sol,
                      char *tipo);
int buscarfilanocero (tiposistema sis, int i);
void intercambiarfilas (tiposistema *sis, int i, int pos);
void hacer0columna (tiposistema *sis, int i);
void comprobarsistema (tiposistema *sis, int f, char *tipo);
void calcularsolucion (tiposistema sis, tiposolucion sol);

int main ()
{
    tiposistema sis;
    tiposolucion sol;
    char tipo;
    int i;

   
    char c;

   
    do  
    {
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
     




        leersistema (&sis);
        resolversistema (sis, sol, &tipo);
        switch (tipo)
        {
        case 'C':
            printf ("\nSistema compatible determinado");
            for (i=0; i<sis.numinc; i++)
                printf ("\nIncognita: %d   Valor: %d", i+1, sol[i]);
            break;
        case 'I':
            printf ("\nSistema incompatible");
            break;
        case 'D':
            printf ("\nSistema compatible indeterminado");
            break;
        }


        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;

}


void leersistema (tiposistema *sis)
{
    int i, j;

    do
    {
        printf ("\nIntroduce numero de ecuaciones (1..%d): ",
                MAXECUACIONES);
        scanf (" %d", &sis->numecu);
    }
    while (sis->numecu < 1 || sis->numecu > MAXECUACIONES);
    do
    {
        printf ("\nIntroduce numero de incognitas (1..%d): ",
                MAXINCOGNITAS);
        scanf (" %d", &sis->numinc);
    }
    while (sis->numinc < 1 || sis->numinc > MAXINCOGNITAS);
    for (i=0; i<sis->numecu; i++)
    {
        printf ("\nEcuacion numero %d", i+1);
        for (j=0; j<sis->numinc; j++)
        {
            printf ("\nIntroduce termino de incognita %d: ", j+1);
            scanf (" %d", &sis->t[i][j]);
        }
        printf ("\nIntroduce termino independiente: ");
        scanf (" %d", &sis->t[i][sis->numinc]);
    }
}

void resolversistema (tiposistema sis, tiposolucion sol,
                      char *tipo)
{
    int i, pos;

    *tipo = ' ';
    i = 0;
    while (*tipo == ' ' && i < sis.numinc)
    {
       
        if (sis.numinc > sis.numecu)
            *tipo = 'D';
        else
        {
            pos = buscarfilanocero (sis, i);
          
            if (pos == -1)
                *tipo = 'D';
            else
            {
                if (pos != i)
                    intercambiarfilas (&sis, i, pos);
                hacer0columna (&sis, i);
                i++;
                comprobarsistema (&sis, i, &*tipo);
            }
        }
    }
    if (*tipo == ' ')
    {
        *tipo = 'C';
        calcularsolucion (sis, sol);
    }
}

int buscarfilanocero (tiposistema sis, int i)
{
    int pos;

    pos = i;
    while (sis.t[pos][i] == 0 && pos < sis.numecu)
    {
        pos++;
    }
    if (pos >= sis.numecu)
        return -1;
    else
        return pos;
}

void intercambiarfilas (tiposistema *sis, int i, int pos)
{
    int j;
    int aux;

    for (j=0; j<sis->numinc+1; j++)
    {
        aux = sis->t[i][j];
        sis->t[i][j] = sis->t[pos][j];
        sis->t[pos][j] = aux;
    }
}

void hacer0columna (tiposistema *sis, int i)
{
    int f, j;
    int coef1, coef2;

    coef1 = sis->t[i][i];
    for (f=i+1; f<sis->numecu; f++)
    {
        coef2 = sis->t[f][i];
        for (j=i; j<sis->numinc+1; j++)
        {
            sis->t[f][j] = coef2 * sis->t[i][j] - coef1 * sis->t[f][j];
        }
    }
}

void comprobarsistema (tiposistema *sis, int f, char *tipo)
{
    int i, j, cont;

 
    i = f;
    while (i < sis->numecu && *tipo ==' ')
    {
        cont = 0;
        for (j=0; j<sis->numinc; j++)
        {
            if (sis->t[i][j] != 0)
                cont++;
        }
        if (cont == 0)
        {
           
            if (sis->t[i][sis->numinc] != 0)
                *tipo = 'I';
            else
            {
               
                intercambiarfilas(&*sis, i, sis->numecu-1);
                sis->numecu--;
            }
        }
        else
            i++;
    }
}

void calcularsolucion (tiposistema sis, tiposolucion sol)
{
    int i, j;
    int suma;

    for (i=sis.numinc-1; i>=0; i--)
    {
       
        suma = sis.t[i][sis.numinc];

        for (j=i+1; j<sis.numinc; j++)
        {
            suma = suma - sis.t[i][j] * sol[j];
        }
        
        sol[i] = suma / sis.t[i][i];
    }
}