#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



void leerdatos (double *a, double *b, double *y0, int *n);
void calcularvalores (double a, double b, double y0, int n);
double f (double x, double y);


int main(){
   
    char c;

    double a, b, y0;
    int n;

   
    do{ system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        

        leerdatos (&a, &b, &y0, &n);
        calcularvalores (a, b, y0, n);

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}


void leerdatos (double *a, double *b, double *y0, int *n)
{
    do
    {
        printf ("\nIntroduce valores del intervalo: ");
        scanf (" %lf %lf", &*a, &*b);
    }while (*a >= *b);
    printf ("\nIntroduce valor y0: ");
    scanf (" %lf", &*y0);
    printf ("\nIntroduce cantidad de terminos: ");
    scanf ( " %d", &*n);
}

void calcularvalores (double a, double b, double y0, int n)
{
    double deltax, x, yeuler, yrunge, yeulerant, yrungeant,
            k1, k2, k3, k4;
double f (double x, double y);
    deltax = (b - a) / n;
    yeulerant = y0;
    yrungeant = y0;
    printf ("\nx=%lf   y euler = %lf    y runge = %lf",
            a, yeulerant, yrungeant);
    for (x=a; x<b; x=x+deltax)
    {
       
        yeuler = yeulerant + f(x, yeulerant) * deltax;
        yeulerant = yeuler;
        
        k1 = deltax * f(x, yrungeant);
        k2 = deltax * f(x+deltax/2, yrungeant+k1/2);
        k3 = deltax * f(x+deltax/2, yrungeant+k2/2);
        k4 = deltax * f(x+deltax, yrungeant+k3);
        yrunge = yrungeant + (k1 + 2*k2 + 2*k3 + k4) / 6;
        yrungeant = yrunge;
        printf ("\nx=%lf   y euler = %lf    y runge = %lf",
            x+deltax, yeuler, yrunge);
    }
}

double f (double x, double y)
{
    return (1+x) * (y*y) / 2;
}