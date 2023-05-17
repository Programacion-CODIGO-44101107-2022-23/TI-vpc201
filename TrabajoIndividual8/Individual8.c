#include <stdio.h>
#include <math.h>

#define MAXIMOCAPITAL 100000
#define MAXIMOANIOS 50
#define MAXIMOINTERES 15

void leerdatos (double *capitalinicial, int *numanios, int *tipocuota,
                double *interesanual);
void calculardatos (double capitalinicial, int numanios, int tipocuota,
        double interesanual, double *interescuota, int *numcuotasanio,
        int *numtotalcuotas, double *cuota);
void escribirtablaamortizacion (double capitalinicial, int numanios,
        int tipocuota, double interesanual, double interescuota,
        int numcuotasanio, int numtotalcuotas, double cuota);
void escribircabecera(double capitalinicial, double interesanual,
                      int numanios, int numtotalcuotas);
void escribirpie(int anio, double amortizadoanio, double interesesanio,
                    double totalamortizado, double totalinteres);

int main ()
{
    double capitalinicial, interesanual, interescuota, cuota;
    int numanios, tipocuota, numcuotasanio, numtotalcuotas;

    leerdatos (&capitalinicial, &numanios, &tipocuota, &interesanual);
    calculardatos (capitalinicial, numanios, tipocuota, interesanual,
                &interescuota, &numcuotasanio, &numtotalcuotas,
                &cuota);
    escribirtablaamortizacion (capitalinicial, numanios, tipocuota,
                interesanual, interescuota, numcuotasanio,
                numtotalcuotas, cuota);
}


void leerdatos (double *capitalinicial, int *numanios, int *tipocuota,
                double *interesanual)
{
    printf ("\nIntroduce datos del prestamo: ");
    do
    {
        printf ("\nIntroduce capital inicial: ");
        scanf (" %lf", capitalinicial);
    }while (*capitalinicial<=0 || *capitalinicial>MAXIMOCAPITAL);
    do
    {
        printf ("\nIntroduce numero de años: ");
        scanf (" %d", numanios);
    }while (*numanios<=0 || *numanios>MAXIMOANIOS);
    do
    {
        printf ("\nTipos de cuotas existentes:");
        printf ("\n1. Anual");
        printf ("\n2. Semestral");
        printf ("\n3. Cuatrimestral");
        printf ("\n4. Trimestral");
        printf ("\n5. Mensual");
        printf ("\nIntroduce tipo de cuota: ");
        scanf (" %d", tipocuota);
    }while (*tipocuota<1 || *tipocuota>5);
    do
    {
        printf ("\nIntroduce interes anual: ");
        scanf (" %lf", interesanual);
    }while (*interesanual<=0 || *interesanual>MAXIMOINTERES);
}

void calculardatos (double capitalinicial, int numanios, int tipocuota,
        double interesanual, double *interescuota, int *numcuotasanio,
        int *numtotalcuotas, double *cuota)
{
    switch (tipocuota)
    {
        case 1: *numcuotasanio = 1; break;
        case 2: *numcuotasanio = 2; break;
        case 3: *numcuotasanio = 3; break;
        case 4: *numcuotasanio = 4; break;
        case 5: *numcuotasanio = 12; break;
    }
    *interescuota = (interesanual/100) / *numcuotasanio;
    *numtotalcuotas = *numcuotasanio * numanios;
    *cuota = (capitalinicial * (*interescuota) *
              pow (1+(*interescuota), (*numtotalcuotas))) /
             (pow (1+(*interescuota), (*numtotalcuotas)) - 1);
}

void escribirtablaamortizacion (double capitalinicial, int numanios,
        int tipocuota, double interesanual, double interescuota,
        int numcuotasanio, int numtotalcuotas, double cuota)
{
    int i, j, n;
    double capitalpendiente, intereses, capamortizado,
        totalamortizado, totalinteres, amortizadoanio,
        interesesanio;

    n = 1;
    capitalpendiente = capitalinicial;
    totalamortizado = 0;
    totalinteres = 0;
    for (i=1; i<=numanios; i++)
    {
        escribircabecera(capitalinicial, interesanual, numanios,
                         numtotalcuotas);
        amortizadoanio = 0;
        interesesanio = 0;
        for (j=1; j<=numcuotasanio; j++)
        {
            intereses = interescuota * capitalpendiente;
            interesesanio = interesesanio + intereses;
            capamortizado = cuota - intereses;
            amortizadoanio = amortizadoanio + capamortizado;
            capitalpendiente = capitalpendiente - capamortizado;
            printf ("\n%8d %10.2lf %10.2lf %10.2lf %13.2lf", n,
                    cuota, capamortizado, intereses, capitalpendiente);
            n++;
        }
        totalamortizado = totalamortizado + amortizadoanio;
        totalinteres = totalinteres + interesesanio;
        escribirpie(i, amortizadoanio, interesesanio,
                    totalamortizado, totalinteres);
    }
}

void escribircabecera(double capitalinicial, double interesanual,
                      int numanios, int numtotalcuotas)
{
    printf ("\n");
    printf ("\n\t\t\tCapital:       %12.2lf", capitalinicial);
    printf ("\n\t\t\tInteres anual: %12.2lf %%", interesanual);
    printf ("\n\t\t\tNumero años:   %9d", numanios);
    printf ("\n\t\t\tNumero plazos: %9d", numtotalcuotas);
    printf ("\n");
    printf ("\nNº plazo      Cuota  Cap amort  Intereses Cap pendiente");
}

void escribirpie(int anio, double amortizadoanio, double interesesanio,
                    double totalamortizado, double totalinteres)
{
    printf ("\n");
    printf ("\n\t\tAño nº: %d", anio);
    printf ("\n\t\t      Capital amortizado:  %11.2lf", amortizadoanio);
    printf ("\n\t\t      Intereses pagados:   %11.2lf", interesesanio);
    printf ("\n\t\tCapital total amortizado:  %11.2lf", totalamortizado);
    printf ("\n\t\tIntereses totales pagados: %11.2lf", totalinteres);
    printf ("\n");
}
