#include "./codice.h"
#include "./risposta.h"
#include "./parametri.h"

#ifndef PARTITA_H_
#define PARTITA_H_

#define MAX_TENT 20
#define ID_DIM 4
typedef struct
{
	codice codiceSegreto;
	parametri parametri;
	int tentativiEffettuati;
	codice tentativi[MAX_TENT];
	risposta risposte[MAX_TENT];
	char identificativo[ID_DIM];

}partita;



codice leggereCodiceSegreto(partita partita);
parametri leggereParametri(partita partita);
int leggereTentativiEffettuati(partita partita);
codice leggereTentativi(partita partita, int indice);
risposta leggereRisposta(partita partita, int indice);
void leggereIdentificativo(partita partita, char id[]);
partita scrivereCodiceSegreto(partita partita, codice codiceSegreto);
partita scrivereParametri(partita partita, parametri parametri);
partita scrivereTentativiEffettuati(partita partita, int numTentativi);
partita scrivereTentativi(partita partita, int indice, codice tentativo);
partita scrivereRisposta(partita partita, int indice, risposta risposta);
partita scrivereIdentificativo(partita partita, char id[]);

#endif /* PARTITA_H_ */
