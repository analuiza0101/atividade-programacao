#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 12

typedef struct {
    char nome[100];
    float preco;
} Produto;

int contarOcorrencias(int *vet, int n, int valor) {
    int i, cont = 0;
    for (i = 0; i < n; i++) {
        if (vet[i] == valor) {
            cont++;
        }
    }
    return cont;
}

int jaProcessado(int *vet, int idx, int valor) {
    int i;
    for (i = 0; i < idx; i++) {
        if (vet[i] == valor) {
            return 1;
        }
    }
    return 0;
}

void ordenarDesc(int *vet, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (vet[j] > vet[i]) {
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

void ordenarProdutosPorNome(Produto *lista, int n) {
    int i, j;
    Produto temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(lista[j].nome, lista[i].nome) < 0) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

int main() {
    int *nums = (int *)malloc(sizeof(int) * TAM);
    int *paresOcc = (int *)malloc(sizeof(int) * TAM);
    int qtdParesOcc = 0;

    Produto *produtos = NULL;
    int totalProdutos = 0;

    int i, j, k, occ;

    for (i = 0; i < TAM; i++) {
        printf("Digite o %do numero inteiro: ", i + 1);
        scanf("%d", &nums[i]);
    }

    /* Cadastro de produtos para numeros distintos com ocorrencia impar */
    for (i = 0; i < TAM; i++) {
        if (!jaProcessado(nums, i, nums[i])) {
            occ = contarOcorrencias(nums, TAM, nums[i]);
            if (occ % 2 != 0) {
                printf("\nNumero %d tem ocorrencia impar (%d). Cadastre %d produto(s):\n",
                       nums[i], occ, occ);
                produtos = (Produto *)realloc(produtos, sizeof(Produto) * (totalProdutos + occ));
                for (k = 0; k < occ; k++) {
                    printf("  Produto %d - Nome: ", k + 1);
                    scanf("%99s", produtos[totalProdutos].nome);
                    printf("  Produto %d - Preco unitario: ", k + 1);
                    scanf("%f", &produtos[totalProdutos].preco);
                    totalProdutos++;
                }
            } else {
                paresOcc[qtdParesOcc++] = nums[i];
            }
        }
    }

    ordenarDesc(paresOcc, qtdParesOcc);
    ordenarProdutosPorNome(produtos, totalProdutos);

    printf("\n=== 12 NUMEROS INFORMADOS ===\n");
    for (i = 0; i < TAM; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("\n=== NUMEROS DISTINTOS E OCORRENCIAS ===\n");
    for (i = 0; i < TAM; i++) {
        if (!jaProcessado(nums, i, nums[i])) {
            printf("Numero %d: %d ocorrencia(s)\n", nums[i], contarOcorrencias(nums, TAM, nums[i]));
        }
    }

    printf("\n=== PRODUTOS CADASTRADOS (ORDEM ALFABETICA) ===\n");
    for (i = 0; i < totalProdutos; i++) {
        printf("Nome: %s | Preco: R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }

    printf("\n=== NUMEROS COM OCORRENCIA PAR (ORDEM DECRESCENTE) ===\n");
    for (i = 0; i < qtdParesOcc; i++) {
        printf("%d ", paresOcc[i]);
    }
    printf("\n");

    free(nums);
    free(paresOcc);
    free(produtos);

    return 0;
}