#include <stdio.h>

const char SEPARACOES[7] = " .,;:\n\t";

int char_separacao(char); //Retorna se é ou não um char de separação

int main() {
    char frase[1024];
    fgets(frase, 1024, stdin); 
    //Dá errado se usar o scanf, porque ele encerra a leitura da string quando tem um " "
    
    char *palavra = frase;
    
    int contador = 0; //Contador de palavras na frase
    int anteriorSep = 1; 
    //Armazena se o char anterior é de separação e também faz com que os chars de separação no início da frase sejam ignorados
    
    while (*palavra != '\0') {
        if (char_separacao(*palavra)){
            if (!anteriorSep)
                anteriorSep = 1;
                contador++;
                
        } else
            anteriorSep = 0;
        
        palavra += sizeof(char);
    }

    printf("%d", contador);
    
    return 0;
}

int char_separacao(char caracter){ 
    for (int i = 0; i < 7; i++){
        if (caracter == SEPARACOES[i])
            return 1;
    }
    
    return 0;
}