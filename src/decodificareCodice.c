#include <stdio.h>
#include <stdlib.h>
#include "./decodificareCodice.h"
#include "./salvarePartita.h"
#include "./topTen.h"



risposta controllareTentativo(codice mioCodice, codice codiceSegreto,
		parametri parametri);
int posizioneSbagliata(int i, char c, codice codiceSegreto, int lunCodice);
void stampaTentativiERisposte(partita partita);
int ricerca(char c, codice codice, int lun);


int decodificareCodice(partita partita) {
	int esito;
	int i;
	char id[ID_DIM];
	codice mioCodice;
	codice codiceSegreto;
	parametri parametri;
	int turniGiocati;
	char maxSimbolo;
	risposta risposta;
	int fine;
	char scelta;
	char c;
	esito = 0;
	codiceSegreto = leggereCodiceSegreto(partita);
	parametri = leggereParametri(partita);
	turniGiocati = leggereTentativiEffettuati(partita);
	maxSimbolo = leggereNumSimboli(parametri) - 1 + 48;
	fine = 0;
	while (fine == 0) {
		system("cls");
		i = 0;
		printf("CODICE SEGRETO : ");
		while (i < leggereLunCodice(parametri)) {
			printf("X ");
			i++;
		}
		printf("\nDevi giocare ancora %d turni\n",
				leggereNumTentativi(parametri) - turniGiocati);

		if (turniGiocati > 0) {
			stampaTentativiERisposte(partita);
		}

		do {
			printf(
					"Inserisci scelta:\n I INSERISCI\n S salva\n\n M Torna al menu\n");
			fflush(stdin);
			scelta = getchar();
			fflush(stdin);
			if (scelta == 'i' || scelta == 's' || scelta == 'm') {
				scelta -= 32;
			}
		} while (scelta != 'I' && scelta != 'S' && scelta != 'M');
		if (scelta == 'I') {
			i = 0;
			while (i < leggereLunCodice(parametri)) {

				do {
					printf("Inserisci simbolo compreso tra 0 e %c -> ",
							maxSimbolo);
					fflush(stdin);
					c = getchar();
					if (leggereRipetuti(parametri)==0)
					{
						if (ricerca(c,mioCodice,i)==1){
							c=maxSimbolo+1;
							printf("IN QUESTA MODALITA' NON SONO CONSENTITE CIFRE RIPETUTE!\n");
						}
					}


					fflush(stdin);
				} while (c < '0' || c > maxSimbolo);

				mioCodice = scrivereValore(mioCodice, i, c);

				i++;
			}
			partita = scrivereTentativi(partita, turniGiocati, mioCodice);
			risposta = controllareTentativo(mioCodice, codiceSegreto, parametri);
			partita = scrivereRisposta(partita, turniGiocati, risposta);
			if (leggereElementoRisposta(risposta, 0)
					== leggereLunCodice(parametri)) {
				esito = 1;
				fine = 1;
				leggereIdentificativo(partita,id);
				printf("CODICE SCOPERTTO \n\n\n");


				if (leggereNumSimboli(parametri)==6)
				{
					salvaTopTen(id,turniGiocati+1,1);
				}

				if (leggereNumSimboli(parametri)==8)
				{
					salvaTopTen(id,turniGiocati+1,2);
				}

				if (leggereNumSimboli(parametri)==10)
				{
					salvaTopTen(id,turniGiocati+1,3);
				}



			}
			turniGiocati++;
			partita = scrivereTentativiEffettuati(partita, turniGiocati);
			if (turniGiocati == leggereNumTentativi(parametri) && esito != 1) {
				fine = 1;
				esito = 2;
				printf("IL CODICE DA INDOVINARE ERA:\t");
				i=0;
				while(i<leggereLunCodice(parametri))
				{
					printf("%c ",leggereValore(codiceSegreto,i));
					i++;
				}
				printf("\n");
			}

		} else {
			if (scelta == 'S') {
				salvarePartita(partita);
			} else {
				fine = 1;
			}
		}
	}
	return esito;
}

risposta controllareTentativo(codice mioCodice, codice codiceSegreto,
		parametri parametri) {
	risposta risposta;
	int i;
	int usati[MAX_DIM];
	int usatiUtente[MAX_DIM];
	int trovato;
	int j;
	risposta = scrivereElementoRisposta(risposta, 0, 0);
	risposta = scrivereElementoRisposta(risposta, 1, 0);
	if (leggereRipetuti(parametri) == 0) {
		i = 0;
		while (i < leggereLunCodice(parametri)) {
			if (leggereValore(mioCodice, i)
					== leggereValore(codiceSegreto, i)) {
				risposta = scrivereElementoRisposta(risposta, 0,
						leggereElementoRisposta(risposta, 0) + 1);
			}
			i++;
		}
		i = 0;
		while (i < leggereLunCodice(parametri)) {
			if (posizioneSbagliata(i, leggereValore(mioCodice, i),
					codiceSegreto, leggereLunCodice(parametri)) == 1) {
				risposta = scrivereElementoRisposta(risposta, 1,
						leggereElementoRisposta(risposta, 1) + 1);
			}
			i++;
		}
	} else {
		i = 0;
		while (i < leggereLunCodice(parametri)) {
			usati[i] = 0;
			usatiUtente[i] = 0;
			i++;
		}
		i = 0;
		while (i < leggereLunCodice(parametri)) {
			if (leggereValore(mioCodice, i) == leggereValore(codiceSegreto, i)) {

				risposta = scrivereElementoRisposta(risposta, 0, leggereElementoRisposta(risposta, 0) + 1);
				usati[i] = 1;
				usatiUtente[i] = 1;
			}
			i++;
		}
		i = 0;
		while (i < leggereLunCodice(parametri)) {
			trovato = 0;
				j = 0;
				while (j < leggereLunCodice(parametri) && trovato == 0) {

					if ((leggereValore(mioCodice,i) == leggereValore(codiceSegreto, j)) && (i != j) && ((usati[j] == 0) && (usatiUtente[i] == 0))) {
						trovato = 1;
						usati[j] = 1;
						usatiUtente[i] = 1;
						risposta = scrivereElementoRisposta(risposta, 1, leggereElementoRisposta(risposta, 1) + 1);
					}
					j++;
				}

			i++;
		}
	}

	return risposta;
}

int posizioneSbagliata(int i, char c, codice codiceSegreto, int lunCodice) {

	int trovato;
	int j;
	trovato = 0;
	j = 0;
	while (j < lunCodice && trovato == 0) {
		if (c == leggereValore(codiceSegreto, j) && i != j) {
			trovato = 1;
		}
		j++;
	}
	return trovato;
}


void stampaTentativiERisposte(partita partita) {
	risposta risposta;
	codice mioTentativo;
	int i;
	int j;
	i = 0;
	while (i < leggereTentativiEffettuati(partita)) {
		printf("TENTATIVO NUMERO %d -> \t", (i + 1));
		risposta = leggereRisposta(partita, i);
		mioTentativo = leggereTentativi(partita, i);
		printf("TUO CODICE: ");
		j = 0;
		while (j < leggereLunCodice(leggereParametri(partita))) {
			printf("%c ", leggereValore(mioTentativo, j));
			j++;
		}
		printf("\t\t %d-%d ", leggereElementoRisposta(risposta, 0),
				leggereElementoRisposta(risposta, 1));
		printf("\n");
		i++;
	}
	return;
}



int ricerca(char c, codice codice, int lun)
{
	int trovato=0;
	int i=0;
	while (i<lun && trovato==0)
	{
		if (c==leggereValore(codice,i))
		{
			trovato=1;
		}
		i++;
	}
	return trovato;
}
