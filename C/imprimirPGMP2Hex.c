// Formatação PGM: https://courses.cs.washington.edu/courses/cse373/00au/pgm.html

#include <stdio.h>
#include <stdlib.h>

void ler_metadados(FILE*, int*, int*, int*);
int** ler_imagem(FILE*, int, int, int);
void imprimir_imagem(int**, int, int);

int main() {
	char nome_arq[256];
	
	printf("Caminho do .pgm a ser lido: ");
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

void ler_metadados(FILE* arq, int* linhas, int* colunas, int* max) {
	char linha[256];
	
	while (fgets(linha, sizeof(linha), arq)) {
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

int** ler_imagem(FILE* arq, int linhas, int colunas, int max) {
	//Cria um array para armazenar os pixels da imagem
	
	int** imagem = malloc(linhas * sizeof(*imagem)); // *imagem -> int*
	
	char linha[4096];
	
	//Copia a imagem do arquivo para o array imagem
	for (int i = 0; i < linhas; i++) {
		imagem[i] = malloc(colunas * sizeof(**imagem)); // **imagem -> int
		
		//Lê a próxima linha composta por pixels, ignorando os comentários
		do {
    			fgets(linha, sizeof(linha), arq);
		} while (linha[0] == '#');
			
		//Cria um ponteiro que vai ficar apontando para o caracter de linha que sucede o último pixel lido
		char* p = linha;
			
		for (int j = 0; j < colunas; j++) {
			int x = (int) strtol(p, &p, 10);
			imagem[i][j] = (x < max) ? x : max; 
		}
	}
		
	return imagem;
}

void imprimir_imagem(int** imagem, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			int pixel = imagem[i][j];
				
			printf((j != colunas-1) ? "%3X " : "%3X", pixel);
		}
		
		printf("\n");
	}
}
