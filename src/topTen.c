#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./topTen.h"
#include "./partita.h"
#include "./record.h"

void visualizzaTopTen(int livello);

void topTen() {
	char c;
	do {
		system("cls");
		do {
			printf(
					"INSERISCI:\nP->TOP-TEN dei principianti\nI->TOP-TEN degli intermedi\nA->TOP-TEN degli avanzati\n\nM->TORNA AL MENU'\n");
			c = getchar();
			fflush(stdin);
			if (c == 'i' || c == 'p' || c == 'a' || c == 'm') {
				c -= 32;
			}
		} while (c != 'I' && c != 'P' && c != 'A' && c != 'M');

		if (c == 'P') {
			visualizzaTopTen(1);
		}

		if (c == 'I') {
			visualizzaTopTen(2);
		}

		if (c == 'A') {
			visualizzaTopTen(3);
		}
	} while (c != 'M');

	return;
}

void visualizzaTopTen(int livello) {
	FILE *f;
	char c;
	int nLetti;
	record classifica[MAX_TOP];
	int i;
	char id[ID_DIM];
	char path[PATH_DIM];
	char principiante[] ="D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\topTen\\Principiante.dat";
	char intermedio[] ="D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\topTen\\Intermedi.dat";
	char avanzato[] ="D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\topTen\\Avanzato.dat";
	system("cls");
	if (livello == 1) {
		strcpy(path, principiante);
	} else {
		if (livello == 2) {
			strcpy(path, intermedio);
		} else {
			strcpy(path, avanzato);
		}
	}

	f = fopen(path, "rb");
	if (f == NULL) {
		printf("Errore nell'apertura del file o TOP-TEN inesistente!\n");
		do {
			printf("PREMI M PER TORNARE AL MENU");
			c = getchar();
			fflush(stdin);
			if (c == 'm') {
				c = 'M';
			}
		} while (c != 'M');
	} else {
		printf("\t\tTOP TEN\n");
		nLetti = fread(classifica, sizeof(record), MAX_TOP, f);
		i = 0;
		while (i < nLetti) {
			leggereId(classifica[i], id);
			printf("POSIZIONE %d----> %s : %d\n", (i + 1), id,
					leggerePunteggio(classifica[i]));
			i++;
		}
	}
	fclose(f);

	do {
		printf("PREMI M PER TORNARE AL MENU\n");
		c = getchar();
		fflush(stdin);
		if (c == 'm') {
			c = 'M';
		}
	} while (c != 'M');
	return;
}


void salvaTopTen(char id[], int punteggio, int livello) {
	FILE *f;
	int i;
	int j;
	int nLetti;
	record classifica[MAX_TOP];
	record newRecord;
	char path[PATH_DIM];
	char principiante[] ="D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\topTen\\Principiante.dat";
	char intermedio[] ="D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\topTen\\Intermedi.dat";
	char avanzato[] ="D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\topTen\\Avanzato.dat";
	if (livello == 1) {
		strcpy(path, principiante);
	} else {
		if (livello == 2) {
			strcpy(path, intermedio);
		} else {
			strcpy(path, avanzato);
		}
	}
	newRecord = scriverePunteggio(newRecord, punteggio);
	newRecord = scrivereId(newRecord, id);
	f =fopen(path,"rb");
	if (f == NULL) {
		printf("ERROR!");
	} else {
		nLetti = fread(classifica, sizeof(record), MAX_TOP, f);
		fclose(f);
		i = 0;
		f =	fopen(path,"wb");
		if (nLetti < MAX_TOP) {
			classifica[nLetti] = newRecord;
			while (i < nLetti) {
				j = i + 1;
				while (j < nLetti + 1) {
					if (leggerePunteggio(classifica[i]) > leggerePunteggio(classifica[j])) {
						newRecord = classifica[i];
						classifica[i] = classifica[j];
						classifica[j] = newRecord;
					}
					j++;
				}
				i++;
			}
		} else {

			while (leggerePunteggio(newRecord)	> leggerePunteggio(classifica[i])) {
					i++;
			}
			j=MAX_TOP-2;
			while (j>=i)
			{
				classifica[j+1]=classifica[j];
				j--;
			}
			classifica[i]=newRecord;
		}
		if (nLetti < 10) {
			nLetti++;
		}
		fwrite(classifica, sizeof(record), nLetti, f);
	}
	fclose(f);

	return;
}

