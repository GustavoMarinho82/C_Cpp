#include <stdio.h>

int somar_salarios_rec(int*, int);

int main() {
	int tamanho = 4;
	int salarios[] = {2000, 1500, 4000, 1200};

	printf("Soma dos Salários: %d\n", somar_salarios_rec(salarios, tamanho));

	return 0;
}

int somar_salarios_rec(int* salarios, int tamanho) {
	if (tamanho == 0)
		return 0;
	
	else
		return salarios[tamanho-1] + somar_salarios_rec(salarios, tamanho-1);
}
