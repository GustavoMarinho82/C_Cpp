#include <stdio.h>
#include <string.h>

int main() {
    const char SEPARACOES[7] = " .,;:\n\t";
    
    char frase[1024];
    fgets(frase, 1024, stdin); 
    //Dá errado se usar o scanf, porque ele encerra a leitura da string quando tem um " "
    
    char *palavra = strtok(frase, SEPARACOES);
    
    int contador = 0; //Contador de palavras da frase
    
    while (palavra != NULL) {
        palavra = strtok(NULL, SEPARACOES);
        contador++;
    }

    printf("%d", contador);
    
    return 0;
}