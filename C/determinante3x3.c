//Cálculo de determinante de uma matriz 3x3 usando a regra de Sarrus
#include <stdio.h>

int main() {
    double matriz[3][3], determinante = 0.0;
    
    for (int i = 0; i < 3; i++)
        scanf("%lf %lf %lf", &matriz[i][0], &matriz[i][1], &matriz[i][2]);

    for (int i = 0; i < 3; i++){
        determinante += matriz[0][i] * matriz[1][((i+1)%3)] * matriz[2][((i+2)%3)];
        determinante -= matriz[0][(2+i)%3] * matriz[1][((1+i)%3)] * matriz[2][i];
    }
    
    printf("%f", determinante);

    return 0;
}