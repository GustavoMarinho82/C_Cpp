#include <stdio.h>

const char SEPARACOES[7] = " .,;:\n\t";

char eh_separacao(char caracter);

int main() {
	char estado = 0;
	// 0 -> Out of word
	// 1 -> In word

	char frase[1024];
	
	printf("Digite uma frase: ");
	fgets(frase, 1024, stdin);
    	
	int contador = 0;
	int p = 0;

	while (frase[p] !=  '\0') {
		switch (estado) {
			case 0:
				if (!eh_separacao(frase[p])) {
					contador++;
					estado = 1;
				}
			break;
			
			case 1:
				if (eh_separacao(frase[p]))
					estado = 0;
			break;
		}
		
		p++;
	}
	
	printf("N° de palavras: %d\n", contador);
	
	return 0;
}

char eh_separacao(char caracter) {
	for (int i = 0; i < 7; i++){
		if (caracter == SEPARACOES[i])
			return 1;
	}
	
	return 0;
}
