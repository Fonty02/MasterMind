/*
 * parametri.h
 *
 *  Created on: 12 May 2022
 *      Author: fonta
 */



#ifndef PARAMETRI_H_
#define PARAMETRI_H_



typedef struct
{
	int numSimboli;
	int lunCodice;
	int ripetuti;
	int numTentativi;
} parametri;


int leggereNumSimboli(parametri par);
int leggereLunCodice(parametri par);
int leggereRipetuti(parametri par);
int leggereNumTentativi(parametri par);
parametri scrivereNumSimboli(parametri par, int numSimboli);
parametri scrivereLunCodice(parametri par, int lunCodice);
parametri scrivereRipetuti(parametri par, int ripetuti);
parametri scrivereNumTentativi(parametri par, int numTentativi);

#endif /* PARAMETRI_H_ */
