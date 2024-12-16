#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ESTA_ENTRE(A, B, C) (((A) <= (B)) && ((B) <= (C)))

void lowercase(char[]);

int main(){
    const char MESES[12][10] = { "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    const int DIAS_MES[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int dia, mes, ano;
    char mes_extenso[10], linha[256];
    
    while (fgets(linha, sizeof(linha), stdin) > 0) { 
        int valido = 0;
        
        if (sscanf(linha, "%d de %s de %d", &dia, mes_extenso, &ano) == 3) { // 01 de janeiro de 2000
            valido = 1, mes = 0;
            lowercase(mes_extenso);
            
            for (int i = 0; i < 12; i++) {
                if (strcmp(mes_extenso, MESES[i]) == 0) {
                    mes = i+1;
                    break;
                }
            }
            
        } else if (sscanf(linha, "%d/%d/%d", &dia, &mes, &ano) == 3) // 01/01/2000
            valido = 1;
            
        if ((valido) && ESTA_ENTRE(1, mes, 12) && ESTA_ENTRE(1, dia, DIAS_MES[mes-1]))
            printf("%02d/%02d/%04d \n", dia, mes, ano);
            
        else
            printf("Data inválida \n");
    }
    
    return 0;
}

void lowercase(char frase[]) {
    while(*frase != '\0')
        *(frase++) = tolower(*frase);
}