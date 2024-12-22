#include <stdio.h>
#include <stdlib.h>

#define LINHAS_IMAGEM 20
#define COLUNAS_IMAGEM 20

char** ler_imagem(FILE*, int*, int*);
void floodfill(char**, int, int);
void imprimir_imagem(char **);

int main() {
	char nome_arq[256];
	
	printf("Arquivo em que será feito o floodfill: ");
	scanf("%s", nome_arq);
	
	FILE* arq = fopen(nome_arq, "r");
	
	if (!arq) {
		fprintf(stderr, "Erro arquivo inexistente\n");
		return 1;
		
	} else {
		int x, y;
		char **imagem = ler_imagem(arq, &x, &y);
		
		fclose(arq);
		
		floodfill(imagem, x, y);
		
		imprimir_imagem(imagem);
		
		for (int i = 0; i < LINHAS_IMAGEM; i++)
			free(imagem[i]);
		free(imagem);
		
		return 0;
	}
}
