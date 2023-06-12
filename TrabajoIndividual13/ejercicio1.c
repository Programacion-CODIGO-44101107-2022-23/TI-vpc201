#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int cara2, cara1, cara0, n, i, m1, m2;
    double porc0, porc1, porc2;
    time_t t;

    srand((unsigned) time(&t));
    printf ("\n       n     0 caras      1 cara     2 caras");
    for (n=10; n<=1000000; n=n*10)
    {
        cara2 = 0;
        cara1 = 0;
        cara0 = 0;
        for (i=1; i<=n; i++)
        {
            m1 = (int) (rand () % 2);
            m2 = (int) (rand () % 2);
            if (m1==0 && m2==0)
                cara2++;
            else
            {
                if (m1==1 && m2==1)
                    cara0++;
                else
                    cara1++;
            }
        }
        porc2 = (double) cara2 * 100 / n;
        porc1 = (double) cara1 * 100 / n;
        porc0 = (double) cara0 * 100 / n;
        printf ("\n%8d %11.2lf %11.2lf %11.2lf", n, porc0, porc1, porc2);
    }
}