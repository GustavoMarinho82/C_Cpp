//Mostra o número do dia no ano de uma data no formato DD MM AAAA
#include <stdio.h>

int main() {
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dia, mes, ano, diaNoAno = 0;
    
    //printf("Digite a data: (DD MM AAAA)\n");
    scanf("%d %d %d", &dia, &mes, &ano);
    
    if (ano % 4 == 0)
        diasMes[1] = 29;
    
    if ((mes > 0) && (mes <= 12) && (dia > 0) && (dia <= diasMes[mes-1])){
        for (int i = 0; i < (mes-1); i++)
            diaNoAno += diasMes[i];
        
        diaNoAno += dia;
    }
    
    printf("%d", diaNoAno);
    
    return 0;
}