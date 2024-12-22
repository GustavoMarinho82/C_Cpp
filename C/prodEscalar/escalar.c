#include <stdio.h>
#include <string.h>

double prod_escalar(double* vet1, double* vet2, int tam) {
	double prodE = 0;
	
	for (int i = 0; i < tam; i++) 
		prodE += vet1[i] * vet2[i];
	
	return prodE;
}

double prod_escalar_rec(double* vet1, double* vet2, int tam) {
	if (tam == 0) {
		return 0;
	
	} else {
		return (vet1[tam-1] * vet2[tam-1]) + prod_escalar(vet1, vet2, tam-1);
	}
}
