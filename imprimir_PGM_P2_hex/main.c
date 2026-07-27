// Formatação PGM: https://courses.cs.washington.edu/courses/cse373/00au/pgm.html

#include <stdio.h>
#include <stdlib.h>

#include "metadados.h"
#include "imagem.h"

int main() {
	char nome_arq[256];
	
	printf("Caminho do PGM a ser lido: ");
	scanf("%s", nome_arq);
	
	FILE* arq = fopen(nome_arq, "r");
	
	if (arq == NULL) {
		fprintf(stderr, "Erro: arquivo inexistente\n");
		
	} else {
		int linhas, colunas, max;
		
		ler_metadados(arq, &linhas, &colunas, &max);
		
		int** imagem = ler_imagem(arq, linhas, colunas, max);
		
		fclose(arq); //Fecha o arquivo, porque ele não será mais utilizado
		
		imprimir_imagem(imagem, linhas, colunas);
		
		for (int i = 0; i < linhas; i++)
			free(imagem[i]);

		free(imagem);
	}
	
	return 0;
}
