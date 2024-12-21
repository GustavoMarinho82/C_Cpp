#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionario.h"

char nome_invalido(char* linha) { //Verifica se o nome presente na linha é inválido
	if (strlen(linha) == 0) 
		return 1;
	
	char nome[TAM_NOME + 1];
	strncpy(nome, linha, TAM_NOME);
	nome[TAM_NOME] = '\0';
		
	for (int i = 0; i < 10; i++) {
		if (strchr(nome, 48+i) != NULL)
			return 1;
	}
	
	return 0;
}

int qtd_funcionarios(FILE* arq) {
	int qtd_func = 0;
	char linha[TAM_LINHA];
	
	while (fgets(linha, sizeof(linha), arq)) {
		if (!nome_invalido(linha))
			qtd_func++;
	}
	
	rewind(arq);
	
	return qtd_func;
}

struct Funcionario** ler_funcionarios(FILE* arq) {
	int qtd_func = qtd_funcionarios(arq);
	
	struct Funcionario** funcionarios = malloc(sizeof(*funcionarios) * qtd_func);
	
	for (int i = 0; i < qtd_func; i++) {
		char linha[TAM_LINHA], *pLinha = linha;
		
		do {
			fgets(linha, sizeof(linha), arq);
		} while (nome_invalido(linha));
		
		funcionarios[i] = malloc(sizeof(**funcionarios));
		
		strncpy(funcionarios[i]->nome, pLinha, TAM_NOME);
		funcionarios[i]->nome[TAM_NOME] = '\0';
		pLinha += TAM_NOME + 1;
		
		char* pNome = funcionarios[i]->nome + TAM_NOME;
		while (*--pNome == ' ');
		*(pNome+1) = '\0';
		
		strncpy(funcionarios[i]->matricula, pLinha, TAM_MATRICULA);
		funcionarios[i]->matricula[TAM_MATRICULA] = '\0';
		pLinha += TAM_MATRICULA + 1;
		
		strncpy(funcionarios[i]->endereco, pLinha, TAM_ENDERECO);
		funcionarios[i]->endereco[TAM_ENDERECO] = '\0';
		pLinha += TAM_ENDERECO + 1;
		
		strncpy(funcionarios[i]->cpf, pLinha, TAM_CPF);
		funcionarios[i]->cpf[TAM_CPF] = '\0';
		pLinha += TAM_CPF + 1;
		
		strncpy(funcionarios[i]->cod_banco, pLinha, TAM_COD_BANCO);
		funcionarios[i]->cod_banco[TAM_COD_BANCO] = '\0';
		pLinha += TAM_COD_BANCO + 1;
		
		strncpy(funcionarios[i]->agencia, pLinha, TAM_AGENCIA);
		funcionarios[i]->agencia[TAM_AGENCIA] = '\0';
		pLinha += TAM_AGENCIA + 1;
		
		strncpy(funcionarios[i]->conta, pLinha, TAM_CONTA);
		funcionarios[i]->conta[TAM_CONTA] = '\0';
		pLinha += TAM_CONTA + 1;
		
		funcionarios[i]->valor_hora = strtod(pLinha, NULL);
	}
	
	rewind(arq);
	
	return funcionarios;
}

void ordenar_funcionarios(struct Funcionarios funcionarios) {
	int qtd_funcs = funcionarios.tamanho;
	struct Funcionario ** funcs = funcionarios.pFuncs;
	
	for (int i = 0; i < qtd_funcs; i++) {
		int menor = i;
		
		for (int j = i+1; j < qtd_funcs; j++) {
			if (strcmp(funcs[i]->nome, funcs[j]->nome) > 0) 
				menor = j;
		}
		
		struct Funcionario* temp = funcs[i];
		funcs[i] = funcs[menor];
		funcs[menor] = temp;
	}
}

int obter_horas_trab(char* matricula, FILE* arq) {
	char linha[TAM_LINHA], mat_linha[TAM_MATRICULA + 1];
	int horas_t;
	
	while (fgets(linha, sizeof(linha), arq)) {
		strncpy(mat_linha, linha, TAM_MATRICULA);
		sscanf(linha+TAM_MATRICULA, "/%d", &horas_t);
		
		if (strcmp(matricula, mat_linha) == 0) {
			rewind(arq);
			
			return horas_t;
		}
	}
	
	rewind(arq);
	
	return 0;
}

void imprimir_folha_pag(struct Funcionarios funcionarios, FILE* arq_mes) {
	int qtd_funcs = funcionarios.tamanho;
	struct Funcionario ** funcs = funcionarios.pFuncs;
	
	for (int i = 0; i < qtd_funcs; i++) {
		struct Funcionario f = *(funcs[i]);
		printf("%-50s|%s|%s|%s|%s|%.2lf\n", f.nome, f.cpf, f.cod_banco, f.agencia, f.conta, (f.valor_hora * obter_horas_trab(f.matricula, arq_mes)));
	}
}
