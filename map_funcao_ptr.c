#include <stdio.h>

void map(int* vet, int tamanho, int (*operacao)(int)) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] =  operacao(vet[i]);
    }
}

int dobrar(int num) {
    return 2 * num;
}

int ao_quadrado(int num) {
    return num * num;
}

int simetrico(int num) {
    return -num;
}

int modulo(int num) {
    return (num >= 0) ? num : -num;
}

void imprimir(int* vet, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    
    printf("\n");
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int (*operacoes[])(int) = {dobrar, ao_quadrado, simetrico, modulo};
    
    for(int i = 0; i < 4; i++) {
        map(vetor, 5, operacoes[i]);
        imprimir(vetor, 5);
    }
    
    return 0;
}
