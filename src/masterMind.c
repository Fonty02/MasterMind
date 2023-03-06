#include <stdio.h>
#include <stdlib.h>
#include "./giocarePartita.h"
#include "./help.h"
#include "./topTen.h"

void menuLoop();


int main(void) {

menuLoop();
}

void menuLoop()
{
    int scelta;
    int continua;
    continua = 1;
    do
    {

        printf("\t\tMASTERMIND\n");
        printf("\n\n  ---- MENU' PRINCIPALE ----\n");
        printf("  1. Gioca Una Partita\n");
        printf("  2. Top 10\n");
        printf("  3. Guida Al Gioco\n");
        printf("  0. Esci\n");

        printf("\n  Scegli un valore valido ");
        scanf("%d", &scelta);
        fflush(stdin);
        system("cls");

        if (scelta >= 0 && scelta <= 3)
        {
            if (scelta == 1)
            {
                giocarePartita();

                system("cls");
            }

             if (scelta == 2)
            {
                topTen();
                system("cls");
            }

             if (scelta == 3)
            {
            	visuallizareRegole();
                system("cls");
            }

             if (scelta == 0)
            {
            	continua = 0;
            }
        }

    } while (continua == 1);

    return;
}
