#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main(){
    char c;



    int a11, a12, a13, b1, a21, a22, a23, b2, a31, a32, a33, b3,
        a42, a43, b4, a52, a53, b5, a62, a63, b6, a73, b7, a83,
        b8, a93, b9, det, x, y, z;



    do{ system("cls");
        printf("Individual 4\n");
        printf("====================================\n\n");



        printf ("Ecuacion: ax + by + cz = d\n");
        printf ("Introduce valores de la primera ecuacion: ");
        scanf (" %d %d %d %d", &a11, &a12, &a13, &b1);
        printf ("Introduce valores de la segunda ecuacion: ");
        scanf (" %d %d %d %d", &a21, &a22, &a23, &b2);
        printf ("Introduce valores de la tercera ecuacion: ");
        scanf (" %d %d %d %d", &a31, &a32, &a33, &b3);
        det = a11*a22*a33 + a12*a23*a31 + a13*a21*a32
                - a13*a22*a31 - a12*a21*a33 - a11*a23*a32;
        if (det == 0)
            printf ("Sistema incompatible o sistema compatible indeterminado");
        else
        {
            printf ("Sistema compatible determinado\n");

            printf ("Sistema inicial\n");
            printf ("%dx + %dy + %dz = %d\n", a11, a12, a13, b1);
            printf ("%dx + %dy + %dz = %d\n", a21, a22, a23, b2);
            printf ("%dx + %dy + %dz = %d\n", a31, a32, a33, b3);

            a42 = a21 * a12 - a11 * a22;
            a43 = a21 * a13 - a11 * a23;
            b4 = a21 * b1 - a11 * b2;
            a52 = a31 * a12 - a11 * a32;
            a53 = a31 * a13 - a11 * a33;
            b5 = a31 * b1 - a11 * b3;
            a62 = a31 * a22 - a21 * a32;
            a63 = a31 * a23 - a21 * a33;
            b6 = a31 * b2 - a21 * b3;

            printf ("Sistema con reduccion de x\n");
            printf ("%dy + %dz = %d\n", a42, a43, b4);
            printf ("%dy + %dz = %d\n", a52, a53, b5);
            printf ("%dy + %dz = %d\n", a62, a63, b6);

            a73 = a52 * a43 - a42 * a53;
            b7 = a52 * b4 - a42 * b5;
            a83 = a62 * a43 - a42 * a63;
            b8 = a62 * b4 - a42 * b6;
            a93 = a62 * a53 - a52 * a63;
            b9 = a62 * b5 - a52 * b6;

            printf ("Sistema con reduccion de y\n");
            printf ("%dz = %d\n", a73, b7);
            printf ("%dz = %d\n", a83, b8);
            printf ("%dz = %d\n", a93, b9);

            if (a73 != 0)
                z = b7 / a73;
            else
            {
                if (a83 != 0)
                    z = b8 / a83;
                else
                    z = b9 / a93;
            }

            if (a42 != 0)
                y = (b4 - a43 * z) / a42;
            else
            {
                if (a52 != 0)
                    y = (b5 - a53 * z) / a52;
                else
                    y = (b6 - a63 * z) / a62;
            }

            if (a11 != 0)
                x = (b1 - a12 * y - a13 * z) / a11;
            else
            {
                if (a21 != 0)
                    x = (b2 - a22 * y - a23 * z) / a21;
                else
                    x = (b3 - a32 * y - a33 * z) / a31;
            }

            printf ("Solución del sistema: ");
            printf ("x = %d\n", x);
            printf ("y = %d\n", y);
            printf ("z = %d\n", z);
        }






        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
