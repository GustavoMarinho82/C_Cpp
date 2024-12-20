#include <stdio.h>
#include <ctype.h>

int main() {
	char nome_arq[256];
	
	printf("Arquivo a ser lido: ");
	scanf("%s", nome_arq);
	
	FILE* arq = fopen(nome_arq, "r");
	
	if (arq == NULL) {
		fprintf(stderr, "Erro no arquivo %s\n", nome_arq);
		
	} else {
        int n_linhas = 0, chars_imprimiveis = 0, chars_lidos = 0, c;
        
		while ((c = getc(arq)) != EOF) {
            if (isprint(c))
                chars_imprimiveis++;
                
            else if (c == 10)
                n_linhas++;
                
            chars_lidos++;
        }
        
        fclose(arq);
        
        printf("Caracteres lidos: %d \nCaracteres imprimíveis: %d \nN° de linhas: %d \n", chars_lidos, chars_imprimiveis, n_linhas);
	}
    
    return 0;
}
