#include <stdio.h>
#include <stdlib.h>

void intercalar(int* V, int inicio, int meio, int fim) {
	int* V_aux = malloc(sizeof(int) * (fim - inicio + 1));
	int i1 = inicio, i2 = meio + 1, i_aux = 0;
	
	while ((i1 <= meio) && (i2 <= fim)) {
		if (V[i1] < V[i2])
			V_aux[i_aux++] = V[i1++];
		
		else
			V_aux[i_aux++] = V[i2++];
	}
	
	while (i1 <= meio)
		V_aux[i_aux++] = V[i1++];
	
	while (i2 <= fim)
		V_aux[i_aux++] = V[i2++];

	for (int i = 0; i < i_aux; i++)
		V[inicio + i] = V_aux[i];
        
	free(V_aux);
}

void merge_sort(int* V, int inicio, int fim) {
	if (fim > inicio) {
		int meio = (inicio + fim) / 2;

		merge_sort(V, inicio, meio);
		merge_sort(V, meio+1, fim);
		intercalar(V, inicio, meio, fim);
	}
}

void swap(int* V, int i, int j) {
	int temp = V[i];
	V[i] = V[j];
	V[j] = temp;
}

int particionar(int* V, int inicio, int fim) {
	int lim_inf = inicio, pivo = (inicio + fim) /2;

	swap(V, pivo, fim); //O pivô agora está no último elemento
	pivo = fim;
	
	while (lim_inf < pivo) {	
		if (V[lim_inf] > V[pivo]) {
			swap(V, lim_inf, pivo-1);
			swap(V, pivo, pivo-1);
			pivo--;
		
		} else
			lim_inf++;
	}
	
	return pivo;
}

void quick_sort(int* V, int inicio, int fim) {
	if (fim > inicio) {
		int pivo = particionar(V, inicio, fim);
		quick_sort(V, inicio, pivo - 1);
		quick_sort(V, pivo + 1, fim);
	}
}
