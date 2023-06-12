#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main(){
    char c;


    int a, h, z, i, j, espa, espa2, h2;



    do{ system("cls");
        printf("Trabajo individual 5\n");
        printf("====================================\n\n");


        do
        {
            printf ("\nIntroduce ancho del cubo (3..20): ");
            scanf (" %d", &a);
        }while (a < 3 || a > 20);
        do
        {
            printf ("\nIntroduce alto del cubo (3..10): ");
            scanf (" %d", &h);
        }while (h < 3 || h > 10);
        do
        {
            printf ("\nIntroduce profundidad del cubo (3..10): ");
            scanf (" %d", &z);
        }while (z < 3 || z > 10);

        espa = z - 1;
        espa2 = 0;
        h2 = 1;
        for (i=1; i<z; i++)
        {
            for (j=1; j<=espa; j++)
            {
                printf ("  ");
            }
            for (j=1; j<=a; j++)
            {
                if (i == 1)
                    printf ("* ");
                else
                {
                    if (j==1 || j==a)
                        printf ("* ");
                    else
                        printf ("  ");
                }
            }
            if (i != 1)
            {
                for (j=1; j<=espa2; j++)
                {
                    printf ("  ");
                }
                printf ("* ");
                h2++;
                if (h2 < h)
                    espa2++;
            }
            printf ("\n");
            espa--;
        }
        for (i=1; i<=h; i++)
        {
            for (j=1; j<=a; j++)
            {
                if (i==1 || i==h)
                    printf ("* ");
                else
                {
                    if (j==1 || j==a)
                        printf ("* ");
                    else
                        printf ("  ");
                }
            }
            if (i != h)
            {
                for (j=1; j<=espa2; j++)
                {
                    printf ("  ");
                }
                printf ("* ");
                h2++;
                if (h2 >= h)
                    espa2--;
            }
            printf ("\n");
        }





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
