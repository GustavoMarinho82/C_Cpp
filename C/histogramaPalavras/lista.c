#include <stdlib.h>
#include <string.h>

#include "lista.h"

//FUNÇÕES ITERATIVAS
struct No* criar_lista(char* texto) {
	struct No* L = NULL;
	char* pPalavra = strtok(texto, SEPARADORES);
	
	while (pPalavra != NULL) {
		inserir_lista(&L, pPalavra);
		pPalavra = strtok(NULL, SEPARADORES);
	}
	
	return L;
}

void inserir_lista(struct No** L, char* palavra) {
	struct No* pAnt = NULL;
	struct No* p = *L;
	char criar_no = 1; //Cria um nó se a palavra não está na lista
	
	while (p != NULL) {
		if (strcmp(p->palavra, palavra) == 0) {
			p->frequencia = p->frequencia + 1;
			p = p->Prox;
			criar_no = 0;
			
		} else if (strcmp(p->palavra, palavra) < 0) {
			pAnt = p;
			p = p->Prox;
		
		} else {
			break;
		}
	}
	
	if (criar_no) {
		struct No* pTemp = malloc(sizeof(**L));
		pTemp->palavra = malloc(sizeof(*(pTemp->palavra)) * (strlen(palavra)+1));
		pTemp->palavra[0] = '\0';
		strcat(pTemp->palavra, palavra);
				
		pTemp->frequencia = 1;
		pTemp->Prox = p;
		
		if (pAnt) { 		
			pAnt->Prox = pTemp;
		
		} else {
			*L = pTemp;
		}
	}
}

void destruir_lista(struct No** L) {
	struct No* p = *L;
	
	while (p != NULL) {
		struct No* p2 = p->Prox;
		free(p->palavra);
		free(p);
		p = p2;
	}
	
	*L = NULL;	
}



//FUNÇÕES RECURSIVAS
void criar_lista_rec2(struct No** L, char* palavra) {
	if (palavra != NULL) {
		inserir_lista(L, palavra);
		
		palavra = strtok(NULL, SEPARADORES);
		
		criar_lista_rec2(L, palavra);
	}
}

struct No* criar_lista_rec(char* texto) {
	struct No* L = NULL;
	char* palavra = strtok(texto, SEPARADORES);
	
	criar_lista_rec2(&L, palavra);
	
	return L;
}

void inserir_lista_rec2(struct No** L, struct No* pAnt, char* palavra) {
	char criar_no = 0;
	
	if (*L == NULL) {
		if (pAnt == NULL) {
			criar_no = 1;
			
		} else {
			criar_no = 1;
		}
	
	} else {
		if (strcmp((*L)->palavra, palavra) == 0) {
			(*L)->frequencia = (*L)->frequencia + 1;
			
		} else if (strcmp((*L)->palavra, palavra) < 0) {
			inserir_lista_rec2(&(*L)->Prox, *L, palavra);
		
		} else {
			criar_no = 1;
		}
	}
	
	if (criar_no) {
		struct No* pTemp = malloc(sizeof(**L));
		pTemp->palavra = malloc(sizeof(*(pTemp->palavra)) * (strlen(palavra)+1));
		pTemp->palavra[0] = '\0';
		strcat(pTemp->palavra, palavra);
					
		pTemp->frequencia = 1;
		pTemp->Prox = *L;
		
		if (pAnt) {
			pAnt->Prox = pTemp;
		
		} else {
			*L = pTemp;
		}
	}
}

void inserir_lista_rec(struct No** L, char* palavra) {
	inserir_lista_rec2(L, NULL, palavra);
}

void destruir_lista_rec(struct No* L) {
	if (L != NULL) {
		destruir_lista_rec(L->Prox);
		free(L->palavra);
		free(L);
	}
}
