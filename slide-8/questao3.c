#include <stdio.h>
#include <stdlib.h>

#define TAM 15

int ehPrimo(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int contarOcc(int *vet, int n, int val) {
    int i, c = 0;
    for (i = 0; i < n; i++) {
        if (vet[i] == val) c++;
    }
    return c;
}

int jaVisto(int *vet, int idx, int val) {
    int i;
    for (i = 0; i < idx; i++) {
        if (vet[i] == val) return 1;
    }
    return 0;
}

int main() {
    int *vet = (int *)malloc(sizeof(int) * TAM);
    char (*animais)[100] = NULL;
    int totalAnimais = 0;
    int i, k, occ;

    for (i = 0; i < TAM; i++) {
        printf("Digite o %do numero inteiro: ", i + 1);
        scanf("%d", &vet[i]);
    }

    printf("\n--- Numeros que aparecem mais de uma vez ---\n");
    for (i = 0; i < TAM; i++) {
        if (!jaVisto(vet, i, vet[i])) {
            occ = contarOcc(vet, TAM, vet[i]);
            if (occ > 1) {
                printf("Numero %d -> %d ocorrencias\n", vet[i], occ);
            }
        }
    }

    /* Regra b: primo e ocorrencia impar -> soma das ocorrencias = vet[i] * occ */
    for (i = 0; i < TAM; i++) {
        if (!jaVisto(vet, i, vet[i])) {
            occ = contarOcc(vet, TAM, vet[i]);
            if (ehPrimo(vet[i]) && occ % 2 != 0) {
                int somaOcc = vet[i] * occ;
                printf("\nNumero %d eh primo e tem ocorrencia impar (%d). Soma das ocorrencias: %d.\n",
                       vet[i], occ, somaOcc);
                animais = realloc(animais, sizeof(*animais) * (totalAnimais + somaOcc));
                for (k = 0; k < somaOcc; k++) {
                    printf("Digite o nome do animal %d: ", totalAnimais + 1);
                    scanf("%99s", animais[totalAnimais]);
                    totalAnimais++;
                }
            }
        }
    }

    printf("\n--- Correspondencia (ocorrencia par -> posicao no vetor) ---\n");
    int numSaida = 1;
    for (i = 0; i < TAM; i++) {
        occ = contarOcc(vet, TAM, vet[i]);
        if (occ > 1 && occ % 2 == 0) {
            /* Posicao 1-based corresponde ao indice i + 1 */
            if (i < totalAnimais) {
                printf("%d. %s\n", numSaida++, animais[i]);
            } else {
                printf("%d. Nao existe correspondencia.\n", numSaida++);
            }
        }
    }

    free(vet);
    free(animais);

    return 0;
}