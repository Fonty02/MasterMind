#include <stdio.h>
#include <stdlib.h>
#include "./codice.h"


char leggereValore(codice codice, int indice)
{
	char valore;
	valore=codice.valori[indice];
	return valore;
}
codice scrivereValore(codice codice, int indice, char valore)
{
	codice.valori[indice]=valore;
	return codice;
}
