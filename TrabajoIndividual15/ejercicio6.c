#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100


typedef struct
{
    double x;
    double y;
} tipopunto2d;

typedef tipopunto2d tipolistavertices[MAX];

typedef struct
{
    int n;
    tipolistavertices v;
} tipopoligono;


void leerpoligono (tipopoligono *pol);
char comprobarregular (tipopoligono pol);
char comprobarconcavoconvexo(tipopoligono pol);
void calcularvector (tipopunto2d p1, tipopunto2d p2, tipopunto2d *v);
void componentez (tipopunto2d v1, tipopunto2d v2, int *contpos,
                  int *contneg, int *contcero);
double calculararea (tipopoligono pol);

int main()
{

    char c;

    tipopoligono pol;
    char regular, concavo;
    double area;

    do
    {
        system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");


        leerpoligono (&pol);
        regular = comprobarregular (pol);
        switch (regular)
        {
        case 'R':
            printf ("\nPoligono regular");
            concavo = comprobarconcavoconvexo(pol);
            switch (concavo)
            {
            case 'X':
                printf ("\nPoligono convexo");
                area = calculararea (pol);
                printf ("\nEl area es: %lf", area);
                break;
            case 'C':
                printf ("\nPoligono concavo");
                break;
            case 'L':
                printf ("\nPoligono degenerado en una linea");
                break;
            }
            break;
        case 'I':
            printf ("\nPoligono irregular");
            break;
        case 'N':
            printf ("\nNo es un poligono");
            break;
        }


        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}

void leerpoligono (tipopoligono *pol)
{
    int i;

    do
    {
        printf ("\nIntroduce el numero de puntos del poligono (1..%d): ", MAX);
        scanf (" %d", &pol->n);
    }
    while (pol->n < 1 || pol->n > MAX);
    for (i=0; i<pol->n; i++)
    {
        printf ("\nPunto %d. Introduce coordenadas x e y: ", i+1);
        scanf (" %lf %lf", &pol->v[i].x, &pol->v[i].y);
    }
}

char comprobarregular (tipopoligono pol)
{
    char r;
    int i, j;
    tipopunto2d p1, p2, p3;
    double y3;

    if (pol.n < 3)
        r = 'N';
    else
    {
        r = 'R';
        i = 2;
        while (i < pol.n && r == 'R')
        {
            j = 0;
            while (j < pol.n-1 && r == 'R')
            {
                if (j != i && j+1 != i)
                {
                    p1 = pol.v[j];
                    p2 = pol.v[j+1];
                    p3 = pol.v[i];
                    y3 = p1.y + ((p3.x-p1.x) / (p2.x-p1.x)) * (p2.y-p1.y);
                    if (y3 == p3.y)
                        r = 'I';
                }
                j++;
            }
            if (r == 'R')
            {
                p1 = pol.v[j];
                p2 = pol.v[0];
                p3 = pol.v[i];
                y3 = p1.y + ((p3.x-p1.x) / (p2.x-p1.x)) * (p2.y-p1.y);
                if (y3 == p3.y)
                    r = 'I';
            }
            i++;
        }
    }
    return r;
}

char comprobarconcavoconvexo(tipopoligono pol)
{
    tipopunto2d vec1, vecant, vecsig;
    int i, contpos, contneg, contcero;

    calcularvector (pol.v[0], pol.v[1], &vec1);
    vecant = vec1;
    contpos = 0;
    contneg = 0;
    contcero = 0;
    for (i=2; i<pol.n; i++)
    {
        calcularvector (pol.v[i-1], pol.v[i], &vecsig);
        componentez (vecant, vecsig, &contpos, &contneg, &contcero);
        vecant = vecsig;
    }
    calcularvector (pol.v[pol.n-1], pol.v[0], &vecsig);
    componentez (vecant, vecsig, &contpos, &contneg, &contcero);
    componentez (vecsig, vec1, &contpos, &contneg, &contcero);
    if (contcero == pol.n)
        return 'L';
    else
    {
        if (contpos != 0 && contneg != 0)
            return 'C';
        else
            return 'X';
    }
}

void calcularvector (tipopunto2d p1, tipopunto2d p2, tipopunto2d *v)
{
    v->x = p2.x - p1.x;
    v->y = p2.y - p1.y;
}

void componentez (tipopunto2d v1, tipopunto2d v2, int *contpos,
                  int *contneg, int *contcero)
{
    double compoz;

    compoz = v1.x * v2.y - v1.y * v2.x;
    if (compoz > 0)
        (*contpos)++;
    else
    {
        if (compoz < 0)
            (*contneg)++;
        else
            (*contcero)++;
    }
}

double calculararea (tipopoligono pol)
{
    double a, l1, l2, l3, s;
    int i;
    tipopunto2d p1, p2, p3;

    a = 0;
    p1 = pol.v[0];
    for (i=2; i<pol.n; i++)
    {
        p2 = pol.v[i-1];
        p3 = pol.v[i];
        l1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        l2 = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
        l3 = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));;
        s = (l1 + l2 + l3) / 2;
        a = a + sqrt(s * (s-l1) * (s-l2) * (s-l3));
    }
    return a;
}