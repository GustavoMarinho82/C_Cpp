#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int[], int);

int main() {
	int n, prod_escalar = 0;
    
	printf("Digite o tamanho dos vetores: ");
	scanf("%d", &n);
    
	int *A = malloc(sizeof(*A)*n);
	int *B = malloc(sizeof(*B)*n);

	printf("Elementos do 1° vetor: \n");
	ler_vetor(A, n);
	printf("Elementos do 2° vetor: \n");
	ler_vetor(B, n);
    
	for (int i = 0; i < n; i++)
		prod_escalar += A[i] * B[i];
        
	printf("Produto escalar: %d\n", prod_escalar);
    
	free(A); free(B);
    
	return 0;
}

void ler_vetor(int V[], int tamanho){
	for (int i = 0; i < tamanho; i++)
		scanf("%d", &V[i]);
}
