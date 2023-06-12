#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int sumarcifras (int n);

int main()
{
 
    char c;


    int n, suma;


    do
    {
        system("cls");
        printf("Ejercicio 1\n");
        printf("====================================\n\n");
        

        
        do
        {
            printf ("\nIntroduce numero natural: ");
            scanf (" %d", &n);
        } while (n < 0);
        suma = sumarcifras (n);  
        printf ("\nLa suma de las cifras es: %d", suma);
        





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }
    while (c!='N');
    return 0;
}



int sumarcifras (int n)
{
    if (n == 0)
        return 0;
    else
        return n%10 + sumarcifras(n/10);
}