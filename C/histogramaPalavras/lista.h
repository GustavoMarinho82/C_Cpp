#ifndef LISTA_H
#define LISTA_H

#define SEPARADORES " ,.-,;:!\n\t"

struct No {
	char* palavra;
	int frequencia;
	struct No* Prox;
};

//FUNÇÕES ITERATIVAS
struct No* criar_lista(char*);
void inserir_lista(struct No**, char*);
void destruir_lista(struct No**);

//FUNÇÕES RECURSIVAS
struct No* criar_lista_rec(char*);
void criar_lista_rec2(struct No**, char*);
void inserir_lista_rec(struct No**, char*);
void inserir_lista_rec2(struct No**, struct No*, char*);
void destruir_lista_rec(struct No*); //Diferente da iterativa, não é atribuido NULL ao No inicial da lista, o que pode ser feito após a chamada da função

#endif
