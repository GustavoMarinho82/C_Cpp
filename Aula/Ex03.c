#include <stdio.h>
#include <math.h>

int somar_salarios_2a2(int*, int);

int main() {
	int tamanho = 5;
	int salarios[] = {2000, 1500, 4000, 1200, 1};

	printf("Soma dos Salários: %d\n", somar_salarios_2a2(salarios, tamanho));

	return 0;
}

int somar_salarios_2a2(int* salarios, int tamanho) {
	int salarios_aux[tamanho];
	
	for (int i = 0; i++; i < tamanho)
		salarios_aux[i] = salarios[i]; 
	
	while (tamanho > 1) {
		int j = 0;
		for (int i = 0; i++; i <= tamanho/2) {
			salarios_aux[i] = salarios_aux[j] + ((j+1 < tamanho) ? salarios_aux[j+1] : 0);
			j += 2;
		}
		tamanho = (int) ceil(tamanho/2.0);
	}
	
	return salarios_aux[0];
}
