#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"

int* ler_array(FILE*, int);

int main() {
	char nome_arq[256];
	
	printf("Digite o nome do arquivo que contém os elementos do array: ");
	scanf("%s", nome_arq);
	
	FILE* arq = fopen(nome_arq, "r");
	
	if (!arq) {
		fprintf(stderr, "Arquivo não encontrado!\n");
		return 1;
		
	} else {
		int num_elementos;
		
		printf("Digite o número de elementos do array: ");
		scanf("%d", &num_elementos);
		
		printf("Lendo o arquivo...\n"); 
		
		int* V1 = ler_array(arq, num_elementos);
		int* V2 = malloc(sizeof(int) * num_elementos);
		
		for (int i = 0; i < num_elementos; i++)
			V2[i] = V1[i];
		
		printf("Ordenando os vetores...\n");
		
		clock_t inicio_merge = clock(), fim_merge, fim_quick;
		
		merge_sort(V1, 0, num_elementos - 1);
		
		fim_merge = clock();
		
		quick_sort(V2, 0, num_elementos - 1);
		
		fim_quick = clock();
		
		double tempo_merge = (double) (fim_merge - inicio_merge) /CLOCKS_PER_SEC, tempo_quick = (double) (fim_quick - fim_merge) /CLOCKS_PER_SEC;
		
		printf("\nTempo gasto usando: \n\tMerge Sort: %lf s\n\tQuick Sort: %lf s\n", tempo_merge, tempo_quick);
		
		free(V1);
		free(V2);
		
		return 0;
	}
}

int* ler_array(FILE* arq, int num_elementos) {
	int* V = malloc(sizeof(int) * num_elementos);
	char* linha = malloc(sizeof(char) * num_elementos * 5);
	
	fgets(linha, num_elementos * 5, arq);
	
	char* num = strtok(linha, ", ");
	
	for (int i = 0; i < num_elementos; i++) {
		V[i] = atoi(num);
		num = strtok(NULL, ",");
	}
	
	free(linha);
	fclose(arq);
	
	return V;
}
