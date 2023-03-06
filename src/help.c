#include <stdio.h>
#include <stdlib.h>
#include "./help.h"

void visuallizareRegole() {
	FILE *f;
	char c;
	char scelta;
	system("cls");
	f =
			fopen("D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\regole\\regole.txt","r");
	if (f == NULL) {
		printf("ERRORE nell'apertura del file!");
	} else {
		c = fgetc(f);
		while (c != EOF) {
			printf("%c", c);
			c = fgetc(f);
		}
	}
	fclose(f);
do
{	printf("\n\nA - Turorial\t\t\t\tM - Menu\n");
	scelta=getchar();
	fflush(stdin);
	if (scelta=='a' || scelta=='m')
	{
		scelta-=32;
	}
}while (scelta!='A' && scelta!='M');

if (scelta=='A')
{
	visualizzareTutorial();
}

return;
}



void visualizzareTutorial() {
	FILE *f;
		char c;
		char scelta;
		system("cls");
		f =
				fopen(
						"D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\regole\\tutorialGioco.txt",
						"r");
		if (f == NULL) {
			printf("ERRORE nell'apertura del file!");
		} else {
			c = fgetc(f);
			while (c != EOF) {
				printf("%c", c);
				c = fgetc(f);
			}
		}
		fclose(f);
	do
	{	printf("\n\nA - Regole\t\t\t\tM - Menu\n");
		scelta=getchar();
		fflush(stdin);
		if (scelta=='a' || scelta=='m')
		{
			scelta-=32;
		}
	}while (scelta!='A' && scelta!='M');

	if (scelta=='A')
	{
		visuallizareRegole();
	}

	return;
}
