/*
Por meio do algoritmo de Euclides, mostre os três resultados baseados em dois números lidos pelo 
canal de entrada padrão: Na primeira linha os quocientes, na segunda os divisores e dividendos 
e na terceira linha os restos. 
*/

#include <stdio.h>

void imprimir_vetor(int[], int);

int main() {
    int quocientes[100], divs[100], restos[100], n = 0;
    
    scanf("%d %d", &divs[0], &divs[1]);
    
    if (divs[1] > divs[0]){
        int temp = divs[1];
        divs[1] = divs[0];
        divs[0] = temp;
    }
    
    do {
        quocientes[n] = divs[n] / divs[n+1];
        divs[n+2] = restos[n] = divs[n] % divs[n+1];
        n++;
        
    } while (restos[n-1] != 0);

    imprimir_vetor(quocientes, n);
    imprimir_vetor(divs, n+1);
    imprimir_vetor(restos, n);
    
    return 0;
}

void imprimir_vetor(int V[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        printf("%d ", V[i]);
    
    printf("\n");
}