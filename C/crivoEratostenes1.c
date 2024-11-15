#include <stdio.h>

int main() {
    int primos[1000], qtd_primos = 0, i_primo;
    
    for (int i = 2; i <= 1000; i++){
        i_primo = 1;
        
        for (int j = 0; j < qtd_primos; j++){
            if (i % primos[j] == 0){
                i_primo = 0;
                break;
            }
        }
        
        if (i_primo){
            primos[qtd_primos] = i;
            qtd_primos++;
            
            printf("%d ", i);
        }
    }

    return 0;
}