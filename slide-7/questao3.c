#include <stdio.h>

int maiorNumero(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n1, n2;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &n1, &n2);

    printf("Maior numero: %d\n", maiorNumero(n1, n2));

    return 0;
}