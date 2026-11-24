#include <stdio.h>

int calcularDobro(int num) {
    return num * 2;
}

int main() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    resultado = calcularDobro(numero);
    printf("O dobro de %d eh %d\n", numero, resultado);

    return 0;
}