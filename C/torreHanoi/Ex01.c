#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "stack.h"

#ifdef _WIN32
    #include <windows.h>
    #define ESPERAR(s) Sleep(s * 1000)
#else
    #include <unistd.h>
    #define ESPERAR(s) sleep((s))
#endif

void imprimir_torres(int, int, ...);
void resolver_torre_hanoi(int, Stack*, Stack*, Stack*);
void mover_discos(int, Stack*, Stack*, Stack*, int, Stack*, Stack*, Stack*);

int main() {
	int qtd_discos;
	
	printf("TORRE DE HANÓI \nQuantos discos na primeira torre: ");
	scanf("%d", &qtd_discos);
	
	Stack* origem = new_stack(qtd_discos);
	Stack* auxiliar = new_stack(qtd_discos);
	Stack* destino = new_stack(qtd_discos);
	
	for (int i = qtd_discos; i > 0; i--) 
		push(origem, i);
	
	imprimir_torres(qtd_discos, 3, origem, auxiliar, destino);
	
	resolver_torre_hanoi(qtd_discos, origem, auxiliar, destino);
	
	destroy_stack(origem);
	destroy_stack(auxiliar);
	destroy_stack(destino);
	
	return 0;
}

void imprimir_torres(int max_altura, int num_args, ...) {
	Stack* torres[num_args];
	int max_largura = max_altura*2 - 1;
	char linha[max_largura + 1];
	
	linha[max_largura] = '\0';
	
	va_list args;
	va_start(args, num_args);
	
	for (int i = 0; i < num_args; i++)
		torres[i] = va_arg(args, Stack*);
	
	va_end(args);
	
	for (int i = max_altura - 1; i >= 0; i--) {
		for (int j = 0; j < num_args; j++) {
			if (length(torres[j]) < i + 1)
				printf("|%*s", max_largura, "");
			
			else {
				int largura = torres[j]->elements[i]*2 - 1;
				int espacos = (max_largura - largura)/2;

				memset(linha, ' ', espacos);
				memset(linha + espacos, '=', largura);
				memset(linha + espacos + largura, ' ', espacos);
				
				printf("|%s", linha);
			}
		}
		
		printf("|\n");
	}
	
	printf("\n");
	ESPERAR(1);
}

void resolver_torre_hanoi(int altura, Stack* origem, Stack* auxiliar, Stack* destino) { 
	// Leva (2^qtd_discos - 1) passos para resolver
	mover_discos(altura, origem, auxiliar, destino, altura, origem, auxiliar, destino);
}

void mover_discos(int qtd_discos, Stack* origem, Stack* auxiliar, Stack* destino, int max_altura, Stack* origem0, Stack* auxiliar0, Stack* destino0) { 
	//Move <qtd_discos> discos da origem até destino usando auxiliar como intermediário
	if (qtd_discos == 1) {
		push(destino, pop(origem));
		imprimir_torres(max_altura, 3, origem0, auxiliar0, destino0);
	
	} else {
		mover_discos(qtd_discos - 1, origem, destino, auxiliar, max_altura, origem0, auxiliar0, destino0);
		
		push(destino, pop(origem));
		imprimir_torres(max_altura, 3, origem0, auxiliar0, destino0);
		
		mover_discos(qtd_discos - 1, auxiliar, origem, destino, max_altura, origem0, auxiliar0, destino0);
	}
}
