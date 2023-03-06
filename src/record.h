/*
 * record.h
 *
 *  Created on: 18 May 2022
 *      Author: fonta
 */

#ifndef RECORD_H_
#define RECORD_H_

#define ID_DIM 4

typedef struct
{
	int punteggio;
	char id[ID_DIM];
}record;


int leggerePunteggio(record record);
void leggereId(record record, char id[]);
record scriverePunteggio(record record, int punteggio);
record scrivereId(record record, char id[]);
#endif /* RECORD_H_ */
