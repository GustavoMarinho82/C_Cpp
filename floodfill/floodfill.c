#include <stdio.h>
#include <stdlib.h>

#include "floodfill.h"

char** ler_imagem(FILE *arq, int *x, int *y) {
	//Assume que o arquivo não possui linhas em branco e que a última linha do arquivo contém as coordenadas iniciais do floodfill, que vão de 0 até LINHA/COLUNA_IMAGEM
	char linha[COLUNAS_IMAGEM + 2];
	char **imagem = malloc(sizeof(*imagem) * LINHAS_IMAGEM);
	
	for (int i = 0; i < LINHAS_IMAGEM; i++) {
		fgets(linha, sizeof(linha), arq);
		
		imagem[i] = malloc(sizeof(**imagem) * COLUNAS_IMAGEM);
		
		for (int j = 0; j < COLUNAS_IMAGEM; j++)
			imagem[i][j] = *(linha + j);
	}
	
	fgets(linha, sizeof(linha), arq);
	sscanf(linha, "%d %d", x, y); 
	
	return imagem;
}

void floodfill(char **imagem, int x, int y) {
	//Preenche o pixel de x e y, se pixel for um ' ', e os ' 's adjacentes a ele com 'X'
	if ((x >= 0) && (x < LINHAS_IMAGEM) && (y >= 0) && (y < COLUNAS_IMAGEM) && (imagem[x][y] == ' ')) {
		imagem[x][y] = 'X';
		
		floodfill(imagem, x+1, y);
		floodfill(imagem, x-1, y);
		floodfill(imagem, x, y+1);
		floodfill(imagem, x, y-1);
	}
}

void imprimir_imagem(char **imagem) {
	for (int i = 0; i < LINHAS_IMAGEM; i++) {
		for (int j = 0; j < COLUNAS_IMAGEM; j++)
			printf("%c", imagem[i][j]);
	
		printf("\n");
	}
}
