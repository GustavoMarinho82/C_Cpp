#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int[], int);

int main() {
    int n, prod_escalar = 0;
    
    scanf("%d", &n);
    
    int *A = (int*) malloc(sizeof(int)*n);
    int *B = (int*) malloc(sizeof(int)*n);
    
    ler_vetor(A, n);
    ler_vetor(B, n);
    
    for (int i = 0; i < n; i++)
        prod_escalar += A[i] * B[i];
        
    printf("%d", prod_escalar);
    
    free(A); free(B);
    
    return 0;
}

void ler_vetor(int V[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        scanf("%d", &V[i]);
}