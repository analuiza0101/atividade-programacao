#include <stdio.h>

int main() {
    int i;
    float nota, soma = 0.0, media;

    for (i = 1; i <= 10; i++) {
        printf("Digite a nota de atendimento do cliente %d (0 a 10): ", i);
        scanf("%f", &nota);
        soma += nota;
    }

    media = soma / 10.0;
    printf("\nMedia geral de atendimento: %.2f\n", media);

    if (media < 7.0) {
        printf("ALERTA: A media geral de atendimento esta abaixo de 7,0!\n");
    }

    return 0;
}
