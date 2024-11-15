#include <stdio.h>
#include <stdbool.h>

void inicializar_vetor(bool[]);
void imprimir_primos(bool[]);

int main() {
    bool eh_primo[1001]; //números primos até 1000 
    inicializar_vetor(eh_primo);
        
    for (int i = 2; i < 1001; i++){
        if (eh_primo[i] != false){
            eh_primo[i] = true;
            
            for (int j = 2*i; j <= 1001; j += i)
                eh_primo[j] = false;
        }
    }

    imprimir_primos(eh_primo);

    return 0;
}

void inicializar_vetor(bool eh_primo[]){
    eh_primo[0] = false; eh_primo[1] = false;

    for (int i = 2; i < 1001; i++)
        eh_primo[i] = true;
}

void imprimir_primos(bool eh_primo[]){
    for (int i = 2; i < 1001; i++){
        if (eh_primo[i])
            printf("%d ", i);
    }
}