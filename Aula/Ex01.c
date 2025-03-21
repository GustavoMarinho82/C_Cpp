#include <stdio.h>

int somar_salarios(int*, int);

int main() {
	int tamanho = 4;
	int salarios[] = {2000, 1500, 4000, 1200};

	printf("Soma dos Salários: %d\n", somar_salarios(salarios, tamanho));

	return 0;
}

int somar_salarios(int* salarios, int tamanho) {
	int soma = 0;

	while (--tamanho >= 0)
		soma += salarios[tamanho];

	return soma;
}
