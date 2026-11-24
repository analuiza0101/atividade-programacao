#include <stdio.h>
#include <stdlib.h>

#define QTD_APOSTADORES 5

long long somaFibonacci(int termos) {
    long long a = 0, b = 1, prox, soma = 0;
    int i;
    for (i = 1; i <= termos; i++) {
        soma += a;
        prox = a + b;
        a = b;
        b = prox;
    }
    return soma;
}

int ehPrimoLL(long long num) {
    long long i;
    if (num < 2) return 0;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    char nomes[QTD_APOSTADORES][100];
    int nTermos[QTD_APOSTADORES];
    long long *resultados = (long long *)malloc(sizeof(long long) * QTD_APOSTADORES);
    int premiado[QTD_APOSTADORES] = {0};

    int i;
    int idx1 = -1, idx2 = -1, idx3 = -1;
    double somaTotal = 0.0, media;

    for (i = 0; i < QTD_APOSTADORES; i++) {
        printf("Nome do apostador %d: ", i + 1);
        scanf("%99s", nomes[i]);
        do {
            printf("Valor inteiro positivo para %s: ", nomes[i]);
            scanf("%d", &nTermos[i]);
        } while (nTermos[i] <= 0);

        resultados[i] = somaFibonacci(nTermos[i]);
        somaTotal += (double)resultados[i];
    }

    media = somaTotal / QTD_APOSTADORES;

    /* 1o lugar: maior primo */
    for (i = 0; i < QTD_APOSTADORES; i++) {
        if (!premiado[i] && ehPrimoLL(resultados[i])) {
            if (idx1 == -1 || resultados[i] > resultados[idx1]) {
                idx1 = i;
            }
        }
    }
    if (idx1 != -1) premiado[idx1] = 1;

    /* 2o lugar: maior par nao premiado */
    for (i = 0; i < QTD_APOSTADORES; i++) {
        if (!premiado[i] && resultados[i] % 2 == 0) {
            if (idx2 == -1 || resultados[i] > resultados[idx2]) {
                idx2 = i;
            }
        }
    }
    if (idx2 != -1) premiado[idx2] = 1;

    /* 3o lugar: maior acima da media nao premiado */
    for (i = 0; i < QTD_APOSTADORES; i++) {
        if (!premiado[i] && (double)resultados[i] > media) {
            if (idx3 == -1 || resultados[i] > resultados[idx3]) {
                idx3 = i;
            }
        }
    }
    if (idx3 != -1) premiado[idx3] = 1;

    /* Exibir em ordem decrescente de classificacao (3o, 2o, 1o) */
    printf("\n=== CLASSIFICACAO FINAL ===\n");
    if (idx3 != -1) {
        printf("3o lugar: %s\n", nomes[idx3]);
    }
    if (idx2 != -1) {
        printf("2o lugar: %s\n", nomes[idx2]);
    }
    if (idx1 != -1) {
        printf("1o lugar: %s\n", nomes[idx1]);
    }

    free(resultados);
    return 0;
}