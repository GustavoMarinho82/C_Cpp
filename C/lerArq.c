#include <stdio.h>

int main() {
	char nome_arq[256];
	
	printf("Arquivo a ser lido: ");
	scanf("%s", nome_arq);
	
	FILE* arq = fopen(nome_arq, "r");
	char linha[256];
	
	if (arq == NULL) {
		perror("");
		return 1;
		
	} else {
		while (fgets(linha, sizeof(linha), arq) != NULL)
			printf("%s", linha);
		
		fclose(arq);
		return 0;
	}
}
