#include <stdio.h>
#include <stdlib.h>
#include "./caricarePartita.h"
#include "./partita.h"
#include "./decodificareCodice.h"

int caricarePartita()
{
	int esito;
	partita partita;
	FILE *file;

	file=fopen("D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\partitaSalvata\\game.dat","rb");
	if (file==NULL)
	{
		esito=-1;
	}
	else
	{
		fread(&partita,sizeof(partita),1,file);
		esito=decodificareCodice(partita);
	}
	fclose(file);
	return esito;

}
