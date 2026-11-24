#include <stdio.h>

int ehPrimo(int num) {
    int i;

    if (num < 2) {
        return 0;
    }

    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (ehPrimo(numero)) {
        printf("O numero %d EH primo.\n", numero);
    } else {
        printf("O numero %d NAO eh primo.\n", numero);
    }

    return 0;
}