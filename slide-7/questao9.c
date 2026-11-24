#include <stdio.h>

void mostrarTabuada(int num) {
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    mostrarTabuada(numero);

    return 0;
}