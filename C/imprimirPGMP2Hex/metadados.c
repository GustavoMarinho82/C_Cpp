#include <stdio.h>
#include <stdlib.h>

void ler_metadados(FILE* arq, int* linhas, int* colunas, int* max) {
	char linha[256];
	
	while (fgets(linha, sizeof(linha), arq) != NULL) {
		//Lê a linha do cabeçalho que contém as linhas e as colunas e atribui às variáveis. Ignorando todas as linhas anteriores
		if (sscanf(linha, "%d %d", colunas, linhas) == 2) 
			break;
	}
		
	//Pula os comentários até chegar no metadado do valor máximo dos pixels
	do {
    		fgets(linha, sizeof(linha), arq);
	} while (linha[0] == '#');
		
	*max = (int) strtol(linha, NULL, 10);
}