#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "relatorio.h"

int main() {
	char texto[100000];
	
	printf("Digite uma frase/texto: \n");
	fgets(texto, sizeof(texto), stdin);
	
	struct No* lista = criar_lista(texto);
	
	imprimir_relatorio(lista);
	
	destruir_lista(&lista); //Iterativa -> &lista | Recursiva -> lista
	//lista = NULL; //Essa linha só é útil caso seja usada a função de destruir recursiva
	
	return 0;
}
