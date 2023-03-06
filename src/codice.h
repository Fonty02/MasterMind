/*
 * codice.h
 *
 *  Created on: 12 May 2022
 *      Author: fonta
 */

#ifndef CODICE_H_
#define CODICE_H_

#define MAX_DIM 4


typedef struct
{
	char valori[MAX_DIM];
}codice;


char leggereValore(codice codice, int indice);
codice scrivereValore(codice codice, int indice, char valore);

#endif /* CODICE_H_ */
