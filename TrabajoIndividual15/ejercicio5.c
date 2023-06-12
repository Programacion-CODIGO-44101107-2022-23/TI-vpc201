#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define MAXFILCOL 3
#define MAXEL 10


typedef struct
{
    char tipo;
    union
    {
        struct
        {
            double tx;
            double ty;
        };
        struct
        {
            double angulo;
        };
        struct
        {
            double sx;
            double sy;
        };
    };
}tipomovimiento;

typedef tipomovimiento tipovector[MAXEL];

typedef struct
{
    int n;
    tipovector v;
}tipodatos;

typedef double tipotabla[MAXFILCOL][MAXFILCOL];

typedef struct
{
    int nfil;
    int ncol;
    tipotabla t;
}tipomatriz;

typedef struct
{
    double x;
    double y;
}tipopunto;


void leerdatos (tipodatos *datos);
void leermovimiento (tipomovimiento *movi);
void calcularmatriz (tipodatos datos, tipomatriz *mat);
void rellenarmatriz (tipomovimiento movi, tipomatriz *mat);
void multiplicarmatrices (tipomatriz m1, tipomatriz m2, tipomatriz *m3);
void copiarmatriz (tipomatriz *mat, tipomatriz m);
void escribirmatriz (tipomatriz mat);
void transformarpunto (tipomatriz mat, tipopunto *p);

int main(){
   
    char c;

    tipodatos datos;
    tipomatriz mat;
    tipopunto p;

    
    do{ system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
   


        leerdatos (&datos);
        calcularmatriz (datos, &mat);
        escribirmatriz(mat);
        do
        {
            printf ("\nIntroduce punto: ");
            scanf (" %lf %lf", &p.x, &p.y);
            transformarpunto (mat, &p);
            printf ("\nPunto transformado (%lf, %lf)", p.x, p.y);
            printf ("\nDesea introducir otro punto (s/n): ");
            c = toupper (getch());
        }while (c == 'S');


        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leerdatos (tipodatos *datos)
{
    int i;

    do
    {
        printf ("\nCuantos movimientos quieres realizar (1..%d): ", MAXEL);
        scanf (" %d", &datos->n);
    }while (datos->n <1 || datos->n > MAXEL);
    for (i=0; i<datos->n; i++)
    {
        printf ("\nMovimento: %d", i+1);
        leermovimiento(&datos->v[i]);
    }
}

void leermovimiento (tipomovimiento *movi)
{
    printf ("\nTipos de movimientos: ");
    printf ("\nT. Traslacion");
    printf ("\nR. Rotacion");
    printf ("\nS. Escalado");
    do
    {
        printf ("\nIntroduce tipo de movimiento (T, R, S): ");
        scanf (" %c", &movi->tipo);
    }while (movi->tipo != 'T' && movi->tipo != 'R' && movi->tipo != 'S');
    switch (movi->tipo)
    {
    case 'T':
        printf ("\nIntroduce traslacion horizontal y vertical: ");
        scanf (" %lf %lf", &movi->tx, &movi->ty);
        break;
    case 'R':
        printf ("\nIntroduce angulo en grados: ");
        scanf (" %lf", &movi->angulo);
        movi->angulo = movi->angulo * M_PI / 180;
        break;
    case 'S':
        printf ("\nIntroduce factores de escalado en direccion X e Y: ");
        scanf (" %lf %lf", &movi->sx, &movi->sy);
        break;
    }
}

void calcularmatriz (tipodatos datos, tipomatriz *mat)
{
    tipomatriz m1, m2;
    int i;

    rellenarmatriz (datos.v[datos.n-1], &*mat);
   
    for (i=datos.n-2; i>=0; i--)
    {
        rellenarmatriz (datos.v[i], &m1);
        multiplicarmatrices (*mat, m1, &m2);
        copiarmatriz (&*mat, m2);
    }
}

void rellenarmatriz (tipomovimiento movi, tipomatriz *mat)
{
    mat->nfil = 3;
    mat->ncol = 3;
    switch (movi.tipo)
    {
    case 'T':
        mat->t[0][0] = 1;
        mat->t[0][1] = 0;
        mat->t[0][2] = movi.tx;
        mat->t[1][0] = 0;
        mat->t[1][1] = 1;
        mat->t[1][2] = movi.ty;
        break;
    case 'R':
        mat->t[0][0] = cos(movi.angulo);
        mat->t[0][1] = - sin (movi.angulo);
        mat->t[0][2] = 0;
        mat->t[1][0] = sin (movi.angulo);
        mat->t[1][1] = cos (movi.angulo);
        mat->t[1][2] = 0;
        break;
    case 'S':
        mat->t[0][0] = movi.sx;
        mat->t[0][1] = 0;
        mat->t[0][2] = 0;
        mat->t[1][0] = 0;
        mat->t[1][1] = movi.sy;
        mat->t[1][2] = 0;
        break;
    }
    mat->t[2][0] = 0;
    mat->t[2][1] = 0;
    mat->t[2][2] = 1;
}

void multiplicarmatrices (tipomatriz m1, tipomatriz m2, tipomatriz *m3)
{
    int i, j, k;
    double sum;

    m3->nfil = m1.nfil;
    m3->ncol = m2.ncol;
    for (i=0; i<m3->nfil; i++)
    {
        for (j=0; j<m3->ncol; j++)
        {
            sum = 0;
            for (k=0; k<m1.ncol; k++)
            {
                sum = sum + m1.t[i][k] * m2.t[k][j];
            }
            m3->t[i][j] = sum;
        }
    }
}

void copiarmatriz (tipomatriz *mat, tipomatriz m)
{
    int i, j;

    mat->nfil = m.nfil;
    mat->ncol = m.ncol;
    for (i=0; i<mat->nfil; i++)
    {
        for (j=0; j<mat->ncol; j++)
        {
            mat->t[i][j] = m.t[i][j];
        }
    }
}

void escribirmatriz (tipomatriz mat)
{
    int i, j;

    printf ("\nLa matriz es:");
    printf ("\n");
    for (i=0; i<MAXFILCOL; i++)
    {
        for (j=0; j<MAXFILCOL; j++)
        {
            printf (" %8.2lf", mat.t[i][j]);
        }
        printf ("\n");
    }
}

void transformarpunto (tipomatriz mat, tipopunto *p)
{
    tipomatriz m1, m2;

    m1.nfil = 3;
    m1.ncol = 1;
    m1.t[0][0] = p->x;
    m1.t[1][0] = p->y;
    m1.t[2][0] = 1;
    multiplicarmatrices(mat, m1, &m2);
    p->x = m2.t[0][0];
    p->y = m2.t[1][0];
}