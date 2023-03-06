#include <stdio.h>
#include <stdlib.h>
#include "./partita.h"

codice leggereCodiceSegreto(partita partita) {
	codice codiceSegreto;
	codiceSegreto = partita.codiceSegreto;
	return codiceSegreto;
}
parametri leggereParametri(partita partita) {
	parametri parametri;
	parametri = partita.parametri;
	return parametri;

}
int leggereTentativiEffettuati(partita partita) {
	int numTentativi;
	numTentativi = partita.tentativiEffettuati;
	return numTentativi;
}
codice leggereTentativi(partita partita, int indice) {
	codice tentativo;
	tentativo = partita.tentativi[indice];
	return tentativo;
}
risposta leggereRisposta(partita partita, int indice) {
	risposta risposta;
	risposta = partita.risposte[indice];
	return risposta;
}


void leggereIdentificativo(partita partita, char id[])
{
	int i=0;
	while (i<(ID_DIM-1))
	{
		id[i]=partita.identificativo[i];
		i++;
	}
	id[i]='\0';
	return;
}
partita scrivereCodiceSegreto(partita partita, codice codiceSegreto) {
	partita.codiceSegreto = codiceSegreto;
	return partita;
}
partita scrivereParametri(partita partita, parametri parametri) {
	partita.parametri = parametri;
	return partita;
}
partita scrivereTentativiEffettuati(partita partita, int numTentativi) {
	partita.tentativiEffettuati = numTentativi;
	return partita;
}
partita scrivereTentativi(partita partita, int indice, codice tentativo) {
	partita.tentativi[indice] = tentativo;
	return partita;
}
partita scrivereRisposta(partita partita, int indice, risposta risposta) {
	partita.risposte[indice] = risposta;
	return partita;
}

partita scrivereIdentificativo(partita partita, char id[])
{
	int i=0;
	while (i<(ID_DIM-1))
	{
		partita.identificativo[i]=id[i];
		i++;
	}
	partita.identificativo[i]='\0';
	return partita;
}

