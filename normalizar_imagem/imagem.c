#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** ler_imagem(FILE *arq, int linhas, int colunas, int max) {
	//Cria um array para armazenar os pixels da imagem
	
	double **imagem = malloc(linhas * sizeof(*imagem));
	
	char linha[4096];
	
	//Copia a imagem do arquivo para o array imagem
	for (int i = 0; i < linhas; i++) {
		imagem[i] = malloc(colunas * sizeof(**imagem));
		
		//Lê a próxima linha composta por pixels, ignorando os comentários
		do {
    			fgets(linha, sizeof(linha), arq);
		} while (linha[0] == '#');
			
		//Cria um ponteiro que vai ficar apontando para o caracter de linha que sucede o último pixel lido
		char* p = linha;
			
		for (int j = 0; j < colunas; j++) {
			double x = strtod(p, &p);
			imagem[i][j] = (x < max) ? x : max; 
		}
	}
		
	return imagem;
}

void imprimir_imagem(double **imagem, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			double pixel = imagem[i][j];
				
			printf((j != colunas-1) ? "%.4lf " : "%.4lf", pixel);
		}
		
		printf("\n");
	}
}

double media_imagem2(double **imagem, int coordenada, int colunas) {
	if (coordenada < 0) {
		return 0;
		
	} else {
		return (media_imagem2(imagem, coordenada-1, colunas) * coordenada + imagem[coordenada / colunas][coordenada % colunas]) / (coordenada+1);
	}
}

double media_imagem(double **imagem, int linhas, int colunas) {
	return media_imagem2(imagem, linhas*colunas-1, colunas);
}

double des_pad_imagem2(double **imagem, int coordenada, int colunas, double media) {
	if (coordenada < 0) {
		return 0;
	
	} else {
		double diferenca = *(imagem[coordenada / colunas] + coordenada % colunas) - media;
		return (diferenca * diferenca) + des_pad_imagem2(imagem, coordenada - 1, colunas, media);
    }
}

double des_pad_imagem(double **imagem, int linhas, int colunas) {
	double media = media_imagem(imagem, linhas, colunas);
	
	return sqrt(des_pad_imagem2(imagem, linhas*colunas-1, colunas, media) / (linhas*colunas-1));
}

void normalizar_imagem(double **imagem, int linhas, int colunas) {
	double media = media_imagem(imagem, linhas, colunas);
	double desvio = des_pad_imagem(imagem, linhas, colunas);
	
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++)
			imagem[i][j] = (imagem[i][j] - media) / desvio;
	}
}
