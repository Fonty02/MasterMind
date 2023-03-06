#include <stdio.h>
#include <stdlib.h>
#include "./parametri.h"

int leggereNumSimboli(parametri par) {
	int numSimboli;
	numSimboli = par.numSimboli;
	return numSimboli;
}
int leggereLunCodice(parametri par) {
	int lunCodice;
	lunCodice = par.lunCodice;
	return lunCodice;
}
int leggereRipetuti(parametri par) {
	int ripetuti;
	ripetuti = par.ripetuti;
	return ripetuti;
}
int leggereNumTentativi(parametri par) {
	int numTentativi;
	numTentativi = par.numTentativi;
	return numTentativi;
}
parametri scrivereNumSimboli(parametri par, int numSimboli) {
	par.numSimboli = numSimboli;
	return par;
}
parametri scrivereLunCodice(parametri par, int lunCodice) {

	par.lunCodice = lunCodice;
	return par;
}
parametri scrivereRipetuti(parametri par, int ripetuti) {

	par.ripetuti = ripetuti;
	return par;
}
parametri scrivereNumTentativi(parametri par, int numTentativi) {

	par.numTentativi = numTentativi;
	return par;
}
