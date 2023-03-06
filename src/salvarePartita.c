#include <stdio.h>
#include <stdlib.h>
#include "./salvarePartita.h"


void salvarePartita(partita partita)
{
		FILE *file;
		file=fopen("D:\\UNIBA\\1 ANNO\\2 SEMESTRE\\Laboratorio\\MasterMind\\MasterMind\\masterMind\\src\\partitaSalvata\\game.dat","wb");
		if (file==NULL)
		{
			printf("ERRORE NELL'APERTURA DEL FILE!\n");
			system("pause");
		}
		else
		{
			fwrite(&partita,sizeof(partita),1,file);
		}
		fclose(file);
	return;
}
