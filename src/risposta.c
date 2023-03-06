#include <stdio.h>
#include <stdlib.h>
#include "./risposta.h"


int leggereElementoRisposta(risposta risposta, int indice)
{
	int valore;
	valore=risposta.risp[indice];
	return valore;
}
risposta scrivereElementoRisposta(risposta risposta, int indice, int valore)
{
	risposta.risp[indice]=valore;
	return risposta;
}
