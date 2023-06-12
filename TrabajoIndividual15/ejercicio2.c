#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXELE 100

typedef struct
{
    double x;
    double y;
} tipopunto;

typedef tipopunto tipovector[MAXELE];

typedef struct
{
    int n;
    tipovector v;
} tipodatos;

void leer_opcion_menu(char *c);
void opcion1(tipodatos *datos);
int buscarpunto (tipodatos datos, tipopunto p);
void opcion2(tipodatos datos);
double interpolar (tipodatos datos, double x);
void opcion3(tipodatos *datos);
void opcion4(void);


int main()
{
    char op;  
    tipodatos datos;

    datos.n = 0;
    do
    {
        printf ("\n\n");
        leer_opcion_menu(&op);
        switch(op)
        {
        case '1':
            opcion1(&datos);
            break;
        case '2':
            opcion2(datos);
            break;
        case '3':
            opcion3(&datos);
            break;
        case '4':
            printf("FIN DE EJECUCION");;
            getch();
            break;
        default:
            printf("\a");
        }
    }
    while(op!='4');
    return 0;
}

void leer_opcion_menu(char *c)
{
    printf("MENU DE OPCIONES:\n");
    printf("=================\n\n");
    printf("\t1.- Insertar un punto en el conjunto\n");
    printf("\t2.- Interpolar un punto\n");
    printf("\t3.- Eliminar todos los puntos\n");
    printf("\t4.- Fin de ejecucion\n");
    printf("\n\t\tIntroduzca opcion: ");
    *c=getch();
}

void opcion1(tipodatos *datos)
{
    tipopunto p;
    int pos, i;

    if (datos->n == MAXELE)
        printf ("\nError, no caben mas puntos");
    else
    {
        printf ("\nIntroduce coordenadas x e y del punto: ");
        scanf (" %lf %lf", &p.x, &p.y);
        pos = buscarpunto (*datos, p);
        if (pos != -1)
            printf ("\nError, ese valor de X ya existe");
        else
        {
        
            i = datos->n - 1;
            while (i >= 0 && datos->v[i].x > p.x)
            {
                datos->v[i+1] = datos->v[i];
                i--;
            }
            datos->v[i+1] = p;
            datos->n++;
        }
    }
}

int buscarpunto (tipodatos datos, tipopunto p)
{
    int i;
    char encon;

    i = 0;
    encon = 'f';
    while (i < datos.n && encon == 'f')
    {
        if (datos.v[i].x == p.x)
            encon = 'v';
        else
            i++;
    }
    if (encon == 'v')
        return i;
    else
        return -1;
}

void opcion2(tipodatos datos)
{
    double x, y;

    if (datos.n == 0)
        printf ("\nNo hay puntos");
    else
    {
        if (datos.n == 1)
            printf ("\nNo hay suficientes puntos");
        else
        {
            printf ("\nIntroduce valor de x: ");
            scanf (" %lf", &x);
            if (x < datos.v[0].x || x > datos.v[datos.n-1].x)
                printf ("\nFuera de rango");
            else
            {
                y = interpolar (datos, x);
                printf ("\ny = %lf", y);
            }
        }
    }
}

double interpolar (tipodatos datos, double x)
{
    double suma, num, den, f;
    int i, j;

    suma = 0;
    for (i=0; i<datos.n; i++)
    {
        
        num = 1;
        den = 1;
        for (j=0; j<datos.n; j++)
        {
            if (j != i)
            {
                num = num * (x - datos.v[j].x);
                den = den * (datos.v[i].x - datos.v[j].x);
            }
        }
        f = num / den;
        suma = suma + f * datos.v[i].y;
    }
    return suma;
}

void opcion3(tipodatos *datos)
{
    if (datos->n == 0)
        printf ("\nNo hay datos para borrar");
    else
        datos->n = 0;
}

void opcion4(void)
{
}