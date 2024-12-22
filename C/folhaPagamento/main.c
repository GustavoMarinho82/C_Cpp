#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"

int main() {
	char nome_arq[256];
	printf("Digite o nome do arquivo que contém as matriculas e as horas trabalhadas: ");
	scanf("%s", nome_arq);
	
	FILE* arq_func = fopen("Funcionarios.txt", "r");
	FILE* arq_mes = fopen(nome_arq, "r");
	
	if (!arq_func || !arq_mes) {
		fprintf(stderr, "Erro na leitura de algum dos arquivos\n");
		return 1;
		
	} else {
		struct Funcionarios funcionarios;
		funcionarios.pFuncs = ler_funcionarios(arq_func);
		funcionarios.tamanho = qtd_funcionarios(arq_func);
		
		ordenar_funcionarios(funcionarios);
		
		imprimir_folha_pag(funcionarios, arq_mes);
		
		fclose(arq_func);
		fclose(arq_mes);
		
		for (int i = 0; i < funcionarios.tamanho; i++)
			free(funcionarios.pFuncs[i]);
		free(funcionarios.pFuncs);
		
		return 0;
	}
}
