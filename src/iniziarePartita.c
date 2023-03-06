#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./iniziarePartita.h"
#include "./decodificareCodice.h"

int iniziarePartita() {
	int esito;
	int n;
	parametri param;
	int valido;
	int numeroCasuale;
	int i;
	int j;
	char identificativo[ID_DIM];
	codice codice;
	partita partita;
	system("cls");
	srand(time(NULL));
	printf(
			"Inserire il livello di difficolta'\n1: Principiante\n2: Intermedio\n3: Avanzato\n");
	do {
		scanf("%d", &n);
		fflush(stdin);
		if (n < 1 || n > 3) {
			printf("Inserire valore valido\n");
		}
	} while (n < 1 || n > 3);

	printf("INSERISCI IDENTIFICATIVO GIOCATORE (3 CARATTERI)\n");
	i=0;
	while (i<(ID_DIM-1))
	{
		printf ("Carattere numero %d = ",(i+1));
		identificativo[i]=getchar();
		fflush(stdin);
		i++;
	}
	identificativo[i]='\0';

	if (n == 1) {
		param = scrivereNumSimboli(param, 6);
		param = scrivereLunCodice(param, 3);
		param = scrivereRipetuti(param, 0);
		param = scrivereNumTentativi(param, 20);
	} else {
		if (n == 2) {
			param = scrivereNumSimboli(param, 8);
			param = scrivereLunCodice(param, 4);
			param = scrivereRipetuti(param, 0);
			param = scrivereNumTentativi(param, 15);
		} else {
			param = scrivereNumSimboli(param, 10);
			param = scrivereLunCodice(param, 4);
			param = scrivereRipetuti(param, 1);
			param = scrivereNumTentativi(param, 9);

		}
	}
	i = 0;
	if (leggereRipetuti(param) == 0) {
		while (i < leggereLunCodice(param)) {
			valido = 1;
			numeroCasuale = (rand() % 10) % leggereNumSimboli(param);
			j = 0;
			while (j < i) {
				if (leggereValore(codice, j) == (numeroCasuale + 48)) {
					j = i;
					valido = 0;
				}
				j++;
			}
			if (valido == 1) {
				codice = scrivereValore(codice, i, (numeroCasuale + 48));
				i++;
			}
		}
	} else {
		while (i < leggereLunCodice(param)) {
			numeroCasuale = (rand() % 10) % leggereNumSimboli(param);
			codice = scrivereValore(codice, i, (numeroCasuale + 48));
			i++;
		}
	}

	partita = scrivereCodiceSegreto(partita, codice);
	partita = scrivereParametri(partita, param);
	partita = scrivereTentativiEffettuati(partita, 0);
	partita=scrivereIdentificativo(partita,identificativo);
	esito=decodificareCodice(partita) ;
	return esito;
}
