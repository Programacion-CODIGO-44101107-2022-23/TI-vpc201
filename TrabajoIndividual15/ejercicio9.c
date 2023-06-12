#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 108
#define MAXE 5
#define MAXF 1000



typedef char cadena2[3];

typedef char cadena15[16];

typedef char cadena30[31];

typedef struct
{
    int z;
    double a;
    cadena2 sim;
    cadena15 nom;
}tipoelemento;

typedef tipoelemento tipotp[MAX];

typedef struct
{
    cadena2 sim;
    int n;
}tipoatomo;

typedef tipoatomo tipovae[MAXE];

typedef struct
{
    cadena30 nom;
    int n;
    tipovae v;
}tipoformula;

typedef tipoformula tipovf[MAXF];

void leer_opcion_menu(char *c);
void leertablaperiodica (cadena30 nombrearchivo, tipotp tp, int *ntp);
void leerformulas (cadena30 nombrearchivo, tipovf vf, int *nf);
void opcion1(tipovf vf, int *nf, tipotp tp, int ntp);
int buscarnombreformula (tipovf vf, int nf, cadena30 nom);
void leerelementos (tipoformula *formu, tipotp tp, int ntp);
int buscarentablaperiodica (tipotp tp, int ntp, cadena2 sim);
void opcion2(tipovf vf, int *nf);
void opcion3(tipovf vf, int nf);
void opcion4(tipovf vf, int nf, tipotp tp, int ntp);
int buscarenformula (tipoformula formu, cadena2 sim);
void grabarformulas (cadena30 nombrearchivo,
                     tipovf vf, int nf);


int main(){
    char op;  

    tipotp tp;
    tipovf vf;
    int ntp, nf;

    leertablaperiodica ("elementos.txt", tp, &ntp);
    leerformulas ("formulas.txt", vf, &nf);

    do{
        leer_opcion_menu(&op);
        switch(op){
        case '1': opcion1(vf, &nf, tp, ntp);
                  break;
        case '2': opcion2(vf, &nf);
                  break;
        case '3': opcion3(vf, nf);
                  break;
        case '4': opcion4(vf, nf, tp, ntp);
                  break;
        case '0': printf("\n\nFIN DE EJECUCION");
                  grabarformulas ("formulas.txt", vf, nf);
                  getch();
        break;
        default:  printf("\a");
        }
    }while(op!='0');
    return 0;
}

void leer_opcion_menu(char *c){
    printf("\n\n");
    printf("MENU DE OPCIONES:\n");
    printf("=================\n\n");
    printf("\t1.- Insertar una formula\n");
    printf("\t2.- Borrar una formula\n");
    printf("\t3.- Listar todas las formulas\n");
    printf("\t4.- Listar formulas que contengan un elemento\n");
    printf("\t0.- Fin de ejecucion\n");
    printf("\n\t\tIntroduzca opcion: ");
    *c=getch();
}

void leertablaperiodica (cadena30 nombrearchivo, tipotp tp, int *ntp)
{
    FILE *f;
    tipoelemento e;

    *ntp = 0;
    f = fopen (nombrearchivo, "r");
    if (f != NULL)
    {
        fscanf (f, "%d", &e.z);
        while ( ! feof (f))
        {
            fscanf (f, "%lf %s %s", &e.a, e.sim, e.nom);
            tp[*ntp] = e;
            *ntp = *ntp + 1;
            fscanf (f, "%d", &e.z);
        }
        fclose (f);
    }
}

void leerformulas (cadena30 nombrearchivo, tipovf vf, int *nf)
{
    FILE *f;
    tipoformula formu;
    int i;

    *nf = 0;
    f = fopen (nombrearchivo, "r");
    if (f != NULL)
    {
        fscanf (f, "%s", formu.nom);
        while ( ! feof (f))
        {
            fscanf (f, "%d", &formu.n);
            vf[*nf] = formu;
            for (i=0; i<formu.n; i++)
            {
                fscanf (f, "%s %d", vf[*nf].v[i].sim,
                        &vf[*nf].v[i].n);
            }
            *nf = *nf + 1;
            fscanf (f, "%s", formu.nom);
        }
        fclose (f);
    }
}

void opcion1(tipovf vf, int *nf, tipotp tp, int ntp)
{
    int pos;

    if (*nf == MAXF)
        printf ("\nNo se pueden insertar mas formulas");
    else
    {
        printf ("\nIntroduce nombre de la formula: ");
        scanf (" %s", vf[*nf].nom);
        pos = buscarnombreformula (vf, *nf, vf[*nf].nom);
        if (pos != -1)
            printf ("\nEsa formula ya existe, no se puede insertar");
        else
        {
            do
            {
                printf ("\nIntroduce numero de elementos en la formula: ");
                scanf (" %d", &vf[*nf].n);
            }while (vf[*nf].n < 1 || vf[*nf].n > MAXE);
            leerelementos (&vf[*nf], tp, ntp);
            *nf = *nf + 1;
        }
    }
}

int buscarnombreformula (tipovf vf, int nf, cadena30 nom)
{
    int i;
    char encon;

    i = 0;
    encon  = 'n';
    while (i < nf && encon == 'n')
    {
        if (strcmp(vf[i].nom, nom) == 0)
            encon = 's';
        else
            i++;
    }
    if (encon == 's')
        return i;
    else
        return -1;
}

void leerelementos (tipoformula *formu, tipotp tp, int ntp)
{
    int i, pos;

    for (i=0; i<formu->n; i++)
    {
        do
        {
            printf ("\nIntroduce simbolo del elemento: ");
            scanf (" %s", formu->v[i].sim);
            pos = buscarentablaperiodica (tp, ntp, formu->v[i].sim);
        }while (pos == -1);
        printf ("\nIntroduce cantidad de elementos: ");
        scanf (" %d", &formu->v[i].n);
    }
}

int buscarentablaperiodica (tipotp tp, int ntp, cadena2 sim)
{
    int i;
    char encon;

    encon = 'n';
    i = 0;
    while (i < ntp && encon == 'n')
    {
        if (strcmp(tp[i].sim, sim) == 0)
            encon = 's';
        else
            i++;
    }
    if (encon == 's')
        return i;
    else
        return -1;
}

void opcion2(tipovf vf, int *nf)
{
    cadena30 nom;
    int pos, i;

    if (*nf == 0)
        printf ("\nNo hay formulas que borrar");
    else
    {
        printf ("\nIntroduce nombre de la formula a borrar: ");
        scanf (" %s", nom);
        pos = buscarnombreformula(vf, *nf, nom);
        if (pos == -1)
            printf ("\nEsa formula no existe");
        else
        {
            for (i=pos; i<*nf-1; i++)
            {
                vf[i] = vf[i+1];
            }
            *nf = *nf - 1;
        }
    }
}

void opcion3(tipovf vf, int nf)
{
    int i, j;

    if (nf == 0)
        printf ("\nNo hay formulas que listar");
    else
    {
        printf ("\nHay %d formulas", nf);
        printf ("\nListado de fórmulas: ");
        for (i=0; i<nf; i++)
        {
            printf ("\n%s compuesto por: ", vf[i].nom);
            for (j=0; j<vf[i].n; j++)
            {
                printf ("\n    %s  %d", vf[i].v[j].sim,
                        vf[i].v[j].n);
            }
        }
    }
}

void opcion4(tipovf vf, int nf, tipotp tp, int ntp)
{
    int i, j, pos, pos2;
    cadena2 sim;

    if (nf == 0)
        printf ("\nNo hay formulas que listar");
    else
    {
        do
        {
            printf ("\nIntroduce simbolo del elemento a buscar: ");
            scanf (" %s", sim);
            pos = buscarentablaperiodica(tp, ntp, sim);
        }while (pos == -1);

        printf ("\nListado de fórmulas que contienen %s: ", sim);
        for (i=0; i<nf; i++)
        {
            pos2 = buscarenformula (vf[i], sim);
            if (pos2 != -1)
            {
                printf ("\n%s compuesto por: ", vf[i].nom);
                for (j=0; j<vf[i].n; j++)
                {
                    printf ("\n    %s  %d", vf[i].v[j].sim,
                            vf[i].v[j].n);
                }
            }
        }
    }
}

int buscarenformula (tipoformula formu, cadena2 sim)
{
    int i;
    char encon;

    encon = 'n';
    i = 0;
    while (i < formu.n && encon == 'n')
    {
        if (strcmp(formu.v[i].sim, sim) == 0)
            encon = 's';
        else
            i++;
    }
    if (encon == 's')
        return i;
    else
        return -1;
}

void grabarformulas (cadena30 nombrearchivo,
                    tipovf vf, int nf)
{
    FILE *f;
    int i, j;

    f = fopen (nombrearchivo, "w");
    if (f != NULL)
    {
        for (i=0; i<nf; i++)
        {
            fprintf (f, "%s %d", vf[i].nom, vf[i].n);
            for (j=0; j<vf[i].n; j++)
            {
                fprintf (f, " %s %d", vf[i].v[j].sim, vf[i].v[j].n);
            }
            fprintf (f, "\n");
        }
        fclose (f);
    }
}