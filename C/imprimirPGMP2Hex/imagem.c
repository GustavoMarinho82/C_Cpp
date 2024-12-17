#include <stdio.h>
#include <stdlib.h>

int* ler_imagem(FILE* arq, int linhas, int colunas, int max) {
	//Cria um array para armazenar os pixels da imagem
	int* imagem = malloc(linhas * colunas * sizeof(*imagem)); 
	
	char linha[4096];
		
	//Copia a imagem do arquivo para o array imagem
	for (int i = 0; i < linhas; i++) {
		//Lê a próxima linha composta por pixels, ignorando os comentários
		do {
    			fgets(linha, sizeof(linha), arq);
		} while (linha[0] == '#');
			
		//Cria um ponteiro que vai ficar apontando para o caracter de linha que sucede o último pixel lido
		char* p = linha;
			
		for (int j = 0; j < colunas; j++) {
			int x = (int) strtol(p, &p, 10);
			imagem[i*colunas + j] = (x < max) ? x : max; 
		}
	}
		
	return imagem;
}

void imprimir_imagem(int* imagem, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			int pixel = imagem[i*colunas + j];
				
			printf((j != colunas-1) ? "%3X " : "%3X", pixel);
		}
		
		printf("\n");
	}
}