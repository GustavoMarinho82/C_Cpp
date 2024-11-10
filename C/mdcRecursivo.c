#include <stdio.h>

int mdc_recursivo(int, int);
int mod(int);

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    
    printf("%d", mdc_recursivo(mod(n1), mod(n2)));
    
    return 0;
}

int mdc_recursivo(int n1, int n2){
    if (n1 == 0)
        return n2;

    else if (n2 == 0)
        return n1;

    else if (n1 > n2)
        return mdc_recursivo((n1 % n2), n2);

    else
        return mdc_recursivo(n1, (n2 % n1));
}

int mod(int n){
    if (n < 0)
        return -n;
    else
        return n;
}