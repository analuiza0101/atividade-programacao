#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenarCrescente(int *vet, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (vet[j] < vet[i]) {
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

int main() {
    int entrada[TAM];
    int *posPares = (int *)malloc(sizeof(int) * TAM);
    int *negImpares = (int *)malloc(sizeof(int) * TAM);
    int qtdPos = 0, qtdNeg = 0, i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o %do numero inteiro: ", i + 1);
        scanf("%d", &entrada[i]);

        if (entrada[i] > 0 && entrada[i] % 2 == 0) {
            posPares[qtdPos++] = entrada[i];
        } else if (entrada[i] < 0 && entrada[i] % 2 != 0) {
            negImpares[qtdNeg++] = entrada[i];
        }
    }

    ordenarCrescente(posPares, qtdPos);
    ordenarCrescente(negImpares, qtdNeg);

    printf("\nPositivos e pares (ordem crescente): ");
    for (i = 0; i < qtdPos; i++) {
        printf("%d ", posPares[i]);
    }
    printf("\n");

    printf("Negativos e impares (ordem crescente): ");
    for (i = 0; i < qtdNeg; i++) {
        printf("%d ", negImpares[i]);
    }
    printf("\n");

    free(posPares);
    free(negImpares);

    return 0;
}