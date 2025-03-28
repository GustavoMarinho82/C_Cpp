#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MuroInfinito {
	int e;
	MuroInfinito* Ant;
	MuroInfinito* Prox;
};

void insere_muro(MuroInfinito**, int);
void imprimir_muro(MuroInfinito*);
int busca_bidirecional(MuroInfinito*, int, int);
MuroInfinito* construir_muro(int, int*);
void destruir_muro(MuroInfinito**);

int main() {
	srand(time(NULL));
	
	int tamanho = rand() % 10 + 1;
	int* valores = (int*) malloc(sizeof(int) * tamanho);
	
	for (int i = 0; i < tamanho; i++)
		valores[i] = rand() % 100;
	
	MuroInfinito* L = construir_muro(tamanho, valores);
	
	printf("Muro: ");
	imprimir_muro(L);
	
	int elemento = valores[rand() % tamanho]; 
	int pos_inicial = rand() % tamanho + 1;
	
	int busca = busca_bidirecional(L, elemento, pos_inicial);
	
	if (busca == -1)
		printf("Elemento não encontrado!\n");
	else 
		printf("O elemento %d está a %d posições da pos. inicial (%d°)\n", elemento, busca, pos_inicial);
	
	destruir_muro(&L);
	
	return 0;
}

void insere_muro(MuroInfinito** L, int x) {
	MuroInfinito* No = (MuroInfinito*) malloc(sizeof(MuroInfinito));
	No->e = x;
	
	if (*L == NULL) {
		No->Prox = No;
		No->Ant = No;
	
	} else {
		No->Ant = (*L)->Ant;
		No->Prox = *L;
		(*L)->Ant->Prox = No;
		(*L)->Ant = No;
	}
	
	(*L) = No;
}

void imprimir_muro(MuroInfinito* L) {
	if (L != NULL) {
		MuroInfinito* p = L;
		
		printf("<- %d", p->e);
		p = p->Prox;
		
		while (p != L) {
			printf(" - %d", p->e);
			p = p->Prox;
		}
	}
	
	printf(" ->\n");
}

int busca_bidirecional(MuroInfinito* L, int elemento, int pos_inicial) {
	//retorna a distância do elemento em relação à posição inicial. Ou -1 caso não seja encontrado
	while (--pos_inicial > 0)
		L = L->Prox;
		
	if (L->e == elemento)
		return 0;
	
	else {
		MuroInfinito* pEsq = L,* pDir = L;
		int passos = 0;
		
		do {
			pEsq = pEsq->Ant;
			pDir = pDir->Prox;
			passos++;
			
			if ((pEsq->e == elemento) || (pDir->e == elemento))
				return passos;
			
		} while ((pEsq != pDir) && (pDir != pEsq->Prox)); 
		
		return -1;
	}
}

MuroInfinito* construir_muro(int tamanho, int* valores) {
	MuroInfinito* L = NULL;
	
	for (int i = 0; i < tamanho; i++)
		insere_muro(&L, valores[i]);
		
	return L;
}

void destruir_muro(MuroInfinito** L) {
	if (L != NULL) {
		MuroInfinito* p = (*L)->Prox;
		
		while (p != *L) {
			p = p->Prox;
			free(p->Ant);
		}
			
		free(*L);
		*L = NULL;
	}
}
