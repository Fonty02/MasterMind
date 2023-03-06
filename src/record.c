#include <stdio.h>
#include <stdlib.h>
#include "./record.h"


int leggerePunteggio(record record)
{
	int punteggio;
	punteggio=record.punteggio;
	return punteggio;
}
void leggereId(record record, char id[])
{
	int i=0;
		while (i<(ID_DIM-1))
		{
			id[i]=record.id[i];
			i++;
		}
		id[i]='\0';
		return;
}
record scriverePunteggio(record record, int punteggio)
{
	record.punteggio=punteggio;
	return record;
}
record scrivereId(record record, char id[])
{
	int i=0;
		while (i<(ID_DIM-1))
		{
			record.id[i]=id[i];
			i++;
		}
		record.id[i]='\0';
return record;
}
