#include <stdio.h>
#include <stdlib.h>

#include "vetinput.h"
#include "escalar.h"

int main() {
	char nome_arq1[256], nome_arq2[256];
	
	printf("Nome do arquivo que contém o 1° vetor: ");
	scanf("%s", nome_arq1);
	printf("Nome do arquivo que contém o 2° vetor: ");
	scanf("%s", nome_arq2);
	
	FILE* arq1 = fopen(nome_arq1, "r");
	FILE* arq2 = fopen(nome_arq2, "r");
	
	if (!arq1 || !arq2) {
		fprintf(stderr, "Erro: arquivo %s não foi encontrado.\n", (!arq1) ? nome_arq1 : nome_arq2);
		return 1;
	
	} else {
		int tam1, tam2;
		
		double* vet1 = ler_vetor(arq1, &tam1);
		double* vet2 = ler_vetor(arq2, &tam2);
		
		int farq1 = fclose(arq1), farq2 = fclose(arq2);
		
		if (farq1 || farq2) {
			fprintf(stderr, "Erro: arquivo %s não pôde ser fechado.\n", (!farq1) ? nome_arq1 : nome_arq2);
			
		} else if (!vet1 || !vet2) {
			fprintf(stderr, "Erro: arquivo %s está corrompido.\n", (!vet1) ? nome_arq1 : nome_arq2);
		
		} else if (tam1 != tam2) {
			fprintf(stderr, "Erro: os vetores possuem comprimentos distintos.\n");
		
		} else {
			printf("Produto escalar dos vetores: %.3lf\n", prod_escalar_rec(vet1, vet2, tam1));
		}
		
		free(vet1);
		free(vet2);
		
		return 0;
	}
}
