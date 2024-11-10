//https://en.wikipedia.org/wiki/IEEE_754-1985#/media/File:IEEE_754_Single_Floating_Point_Format.svg
//Código para mostrar a representação binária de um float
#include <stdio.h>

union pontoFlutuante {
    float _float;
    int _int;
};
    
int main() {
    union pontoFlutuante pontof;

    scanf("%f", &pontof._float);
    
    for (int i = 31; i >= 0; i--)
        printf("%d", (pontof._int >> i) & 1);
    
    return 0;
}