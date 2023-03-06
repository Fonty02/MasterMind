/*
 * risposta.h
 *
 *  Created on: 12 May 2022
 *      Author: fonta
 */

#ifndef RISPOSTA_H_
#define RISPOSTA_H_

#define DIM 2

typedef struct
{
	int risp[DIM];
}risposta;


int leggereElementoRisposta(risposta risposta, int indice);
risposta scrivereElementoRisposta(risposta risposta, int indice, int valore);

#endif /* RISPOSTA_H_ */
