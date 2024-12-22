#include <stdio.h>
#include <string.h>

int main() {
	const char SEPARACOES[] = " .,;:\n\t";
	char frase[1024];
    
	printf("Digite um frase: ");
	fgets(frase, sizeof(frase), stdin); 

	char *palavra = strtok(frase, SEPARACOES);
    
	int contador = 0; //Contador de palavras da frase
    
	while (palavra != NULL) {
		palavra = strtok(NULL, SEPARACOES);
		contador++;
	}

	printf("Quantidade de palavras: %d\n", contador);
    
	return 0;
}
