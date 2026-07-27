#include <stdio.h>
#include <stdlib.h>

double* ler_vetor(FILE* arq, int* tam) {
	char linha[64], *pLinha;
	
	if (fgets(linha, sizeof(linha), arq) == NULL)
		return NULL;
	
	*tam = (int) strtol(linha, NULL, 10);
	
	double* vetor = malloc(sizeof(*vetor) * *tam);
	 
	for (int i = 0; i < *tam; i++) {
		if (fgets(linha, sizeof(linha), arq) == NULL)
			return NULL;
		
		sscanf(linha, "%lf", vetor+i);
	}
	
	return vetor;
}
