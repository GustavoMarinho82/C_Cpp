#include <stdio.h>
#include <stdlib.h>

void selection_sort_dec(double[], int);

int main() {
	int tamanho;
    
	printf("Tamanho do vetor: ");
	scanf("%d", &tamanho);
    
	double *vetor = malloc(sizeof(*vetor)*tamanho);
    
	printf("Elementos do vetor: \n");
    
	for (int i = 0; i < tamanho; i++)
		scanf("%lf", &vetor[i]);
    
	selection_sort_dec(vetor, tamanho);
    
	printf("Vetor ordenado decrescentemente: \n");
    
	for (int i = 0; i < tamanho; i++)
		printf("%lf ", vetor[i]);

	printf("\n");
	        
	free(vetor);
    
	return 0;
}

void selection_sort_dec(double vetor[], int tamanho){ //θ(tamanho^2)
	if (tamanho > 1){
		int menor = 0;

		for (int i = 1; i < tamanho; i++){
			if (vetor[menor] > vetor[i])
				menor = i;
		}
        
		double temp = vetor[menor];
		vetor[menor] = vetor[tamanho-1];
		vetor[tamanho-1] = temp;
        
		selection_sort_dec(vetor, tamanho-1);
	}
}
