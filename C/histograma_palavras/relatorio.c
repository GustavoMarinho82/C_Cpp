#include <stdio.h>

#include "lista.h"

//FUNÇÃO ITERATIVA
void imprimir_relatorio(struct No* L) {
	struct No* p = L;
	
	while (p != NULL) {
		printf("%s\t\t%d\n", p->palavra, p->frequencia);
		p = p->Prox;
	}
}

//FUNÇÃO RECURSIVA
void imprimir_relatorio_rec(struct No* L) {
	if (L != NULL) {
		printf("%s\t\t%d\n", L->palavra, L->frequencia);
		imprimir_relatorio_rec(L->Prox);
	}
}
