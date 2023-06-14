#include <stdio.h>

#define MAXN 8
#define MAXL 4

typedef int tipotabla[MAXN][MAXL];

char nombrel[MAXL] = {'s', 'p', 'd', 'f'};
int maximol[MAXL] = {2, 6, 10, 14};

void inicializartabla (tipotabla tab);
void acumular (tipotabla tab, int n);
void escribirtabla (tipotabla tab);
void escribirfrase (tipotabla tab);

int main ()
{
    tipotabla tab;
    int n;

    do
    {
        printf ("\nIntroduce numero de electrones: ");
        scanf ("%d", &n);
    }while (n<=0);
    inicializartabla (tab);
    acumular (tab, n);
    escribirtabla (tab);
    escribirfrase (tab);
}

void inicializartabla (tipotabla tab)
{
    int i, j;

    for (i=0; i<MAXN; i++)
        for (j=0; j<MAXL; j++)
            tab[i][j] = 0;
}

void acumular (tipotabla tab, int n)
{
    int i, j, aux, finj;

    aux = n;
    i = 0;
    while (aux > 0)
    {
        j = 0;
        switch(i+1)
        {
            case 1: finj = 1;
                    break;
            case 2: finj = 2;
                    break;
            case 3: finj = 3;
                    break;
            case 4: finj = 4;
                    break;
            case 5: finj = 3;
                    break;
            case 6: finj = 2;
                    break;
            case 7: finj = 1;
                    break;
            case 8: finj = 0;
                    break;
        }
        while (aux>0 && j<finj)
        {
            if (aux>=maximol[j])
            {
                tab[i][j] = maximol[j];
                aux = aux - maximol[j];
            }
            else
            {
                tab[i][j] = aux;
                aux = 0;
            }
            j++;
        }
        i++;
    }
}

void escribirtabla (tipotabla tab)
{
    int i, j;

    printf ("\n\n");
    for (j=0; j<MAXL; j++)
        printf ("    %c", nombrel[j]);
    printf ("\n");
    for (i=MAXN-1; i>=0; i--)
    {
        printf ("\n%d  ", (i+1));
        for (j=0; j<MAXL; j++)
            printf ("%2d   ", tab[i][j]);
    }
}

void escribirfrase (tipotabla tab)
{
    int i, j;

    printf ("\n\n");
    for (i=0; i<MAXN; i++)
    {
        for (j=0; j<MAXL; j++)
        {
            if (tab[i][j] != 0)
                printf ("%d%c%d  ", (i+1), nombrel[j], tab[i][j]);
        }
        printf ("\n");
    }
}