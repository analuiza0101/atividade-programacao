#include <stdio.h>

int main() {
    int vetor[10];
    int i, buscado, ocorrencias = 0;

    for (i = 0; i < 10; i++) {
        printf("Digite o %do numero inteiro: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite um numero para pesquisar: ");
    scanf("%d", &buscado);

    for (i = 0; i < 10; i++) {
        if (vetor[i] == buscado) {
            ocorrencias++;
        }
    }

    if (ocorrencias == 0) {
        printf("O numero %d nao foi encontrado no array.\n", buscado);
    } else {
        printf("O numero %d foi encontrado %d vez(es).\n", buscado, ocorrencias);
        printf("Posicoes: ");

        int impressos = 0;
        for (i = 0; i < 10; i++) {
            if (vetor[i] == buscado) {
                printf("%d", i + 1);
                impressos++;
                if (impressos < ocorrencias) {
                    printf(", ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}