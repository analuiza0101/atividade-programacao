#include <stdio.h>

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

int main() {
    float n1, n2, resultado;
    int opcao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("\nEscolha a operacao:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            resultado = somar(n1, n2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2:
            resultado = subtrair(n1, n2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3:
            resultado = multiplicar(n1, n2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4:
            if (n2 != 0.0) {
                resultado = dividir(n1, n2);
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("Erro: divisao por zero nao eh permitida.\n");
            }
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}