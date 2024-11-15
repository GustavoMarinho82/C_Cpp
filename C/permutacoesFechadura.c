/*
O esquema abaixo representa uma fechadura eletrônica. Suponha que estamos tentando adivinhar o segredo da fechadura e que viu de longe alguém digitando e conseguindo acesso. Só que para cada dígito visto, há uma chance de erro e o verdadeiro dígito pode ser o próprio número ou então um adjacente.

Escreva um algoritmo que a partir de um número inteiro com até 4 dígitos, gere e imprima todas as variações possíveis usando os próprios dígitos ou dígitos adjacentes aos informados na entrada do programa. Cada dígito adjacente pode ser um dígito vizinho na horizontal ou na vertical, conforme esquema abaixo:

┌───┬───┬───┐
│ 1 │ 2 │ 3 │
├───┼───┼───┤
│ 4 │ 5 │ 6 │
├───┼───┼───┤
│ 7 │ 8 │ 9 │
└───┼───┼───┘
    │ 0 │
    └───┘

Dígitos e suas adjacências:

0: 8
1: 2 4
2: 1 3 5
3: 2 6
4: 1 5 7
5: 2 4 6 8
6: 3 5 9
7: 4 8
8: 0 5 7 9
9: 6 8

Atenção: o dígito 0 (zero) é significativo em qualquer posição. Nas combinações deve-se seguir a ordem de busca em profundidade e exibir sempre primeiro os dígitos originais em cada nível e depois os adjacentes, conforme exemplos abaixo:
 
- Exemplos:

Entrada: 0 Saída: 0 8

Entrada: 5 Saída: 5 2 4 6 8

Entrada: 05 Saída: 05 02 04 06 08 85 82 84 86 88

Entrada: 740 Saída: 740 748 710 718 750 758 770 778 440 448 410 418 450 458 470 478 840 848 810 818 850 858 870 878
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int ADJACENTES[10][5] = { //Também inclue o próprio número, para fins práticos
    {0,8,-1,-1,-1},
    {1,2,4,-1,-1},
    {2,1,3,5,-1},
    {3,2,6,-1,-1},
    {4,1,5,7,-1},
    {5,2,4,6,8},
    {6,3,5,9,-1},
    {7,4,8,-1,-1},
    {8,0,5,7,9},
    {9,6,8,-1,-1}
};

void imprimir_permutacao(int[], int, int);

int main() {
    //Lendo o número base das permutações
    char buffer[4]; //O número deve estar entre o intervalo de [0, 9999]. Se quiser aumentar esse intervalo, aumente o tamanho da variável buffer
    scanf("%s", buffer);

    int tamanho = strlen(buffer);
    int *V = (int*) malloc(sizeof(int)*tamanho);
    
    for (int i = 0; i < tamanho; i++)
        V[i] = buffer[i] - '0';
    
    //Fazendo as permutações
    for (int i = 0; i < pow(5, tamanho); i++)
        imprimir_permutacao(V, tamanho, i);

    free(V);
    
    return 0;
}

void imprimir_permutacao(int V[], int tamanho, int n_permutacao){
    char *permutacao_str = (char*) malloc(sizeof(char)*tamanho);
    int permutacao_valida = 1;
    
    for (int i = 0; ((permutacao_valida) && (i < tamanho)); i++){
        int x = V[i], y = (n_permutacao / pow(5, tamanho-i-1)); 
        n_permutacao %= (int) pow(5, tamanho-i-1);
        
        if (ADJACENTES[x][y] == -1)
            permutacao_valida = 0;
        
        else
            permutacao_str[i] = ADJACENTES[x][y] + '0';
    }
    
    if (permutacao_valida)
        printf("%s ", permutacao_str);
        
    free(permutacao_str);
}