#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#ifndef TAM_LINHA
#define TAM_LINHA 2048
#endif

#ifndef TAM_NOME
#define TAM_NOME 50
#define TAM_MATRICULA 12
#define TAM_ENDERECO 65
#define TAM_CPF 11
#define TAM_COD_BANCO 3
#define TAM_AGENCIA 5
#define TAM_CONTA 8
#endif

struct Funcionario {
	char nome[TAM_NOME + 1];
	char matricula[TAM_MATRICULA + 1];
	char endereco[TAM_ENDERECO + 1];
	char cpf[TAM_CPF + 1];
	char cod_banco[TAM_COD_BANCO + 1];
	char agencia[TAM_AGENCIA + 1];
	char conta[TAM_CONTA + 1];
	double valor_hora;
};

struct Funcionarios {
	struct Funcionario** pFuncs;
	int tamanho;
};

char nome_invalido(char*);
int qtd_funcionarios(FILE*);
struct Funcionario** ler_funcionarios(FILE*);
void ordenar_funcionarios(struct Funcionarios);
int obter_horas_trab(char*, FILE*);
void imprimir_folha_pag(struct Funcionarios, FILE*);

#endif
