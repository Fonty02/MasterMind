#include <stdio.h>
#include <stdlib.h>
#include "./iniziarePartita.h"
#include "./caricarePartita.h"

void giocarePartita() {
	int esito;
	char c;
	do {
		printf(
				"PREMI:\nN -> Nuova partita\nP -> Carica partita\nM -> TORNA AL MENU\n");
		c = getchar();
		fflush(stdin);
		if (c == 'm' || c == 'n' || c == 'p') {
			c -= 32;
		}
	} while ((c != 'M') && (c != 'N') && (c != 'P'));
	if (c != 'M') {
		if (c == 'N') {
			esito = iniziarePartita();

		}
		if (c == 'P') {
			esito = caricarePartita();
		}

		if (esito == 2) {
			printf("CHE PECCATO! HAI PERSO LA SCORSA PARTITA!");
		}
		if (esito == 1) {
			printf("WOW! HAI VINTO LA SCORSA PARTITA!");
		}
		if (esito==-1)
		{
			printf("ERRORE NELL'APERTURA DEL FILE");
		}

		if (esito==0)
				{
					printf("PARTITA INTERROTTA");
				}

		printf("PREMI INVIO PER TORNARE AL MENU");
		c=getchar();
		fflush(stdin);
	}
	return;
}
