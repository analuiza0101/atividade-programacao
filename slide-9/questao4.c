#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int registro;
    int horas_aula;
} Professor;

Professor *lerProfessoresDoArquivo(const char *nomeArquivo, int *qtdLida) {
    FILE *fp = fopen(nomeArquivo, "rb");
    long tamanhoBytes;
    int n;
    Professor *lista;

    *qtdLida = 0;
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    tamanhoBytes = ftell(fp);
    rewind(fp);

    n = (int)(tamanhoBytes / (long)sizeof(Professor));
    if (n <= 0) {
        fclose(fp);
        return NULL;
    }

    lista = (Professor *)malloc((size_t)n * sizeof(Professor));
    if (lista == NULL) {
        fclose(fp);
        return NULL;
    }

    if (fread(lista, sizeof(Professor), (size_t)n, fp) != (size_t)n) {
        free(lista);
        fclose(fp);
        return NULL;
    }

    *qtdLida = n;
    fclose(fp);
    return lista;
}

int main() {
    int n, i, qtdCarregada = 0;
    Professor *profs;
    void *bufferBruto;
    Professor *profsCarregados;
    FILE *fp;

    printf("Quantos professores deseja cadastrar (N)? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    profs = (Professor *)malloc((size_t)n * sizeof(Professor));
    bufferBruto = malloc((size_t)n * sizeof(Professor));

    if (profs == NULL || bufferBruto == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(profs);
        free(bufferBruto);
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Professor %d - Registro: ", i + 1);
        scanf("%d", &profs[i].registro);
        printf("Professor %d - Horas aula: ", i + 1);
        scanf("%d", &profs[i].horas_aula);
    }

    memcpy(bufferBruto, profs, (size_t)n * sizeof(Professor));

    fp = fopen("folha.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir folha.dat para escrita.\n");
        free(profs);
        free(bufferBruto);
        return 1;
    }

    fwrite(bufferBruto, (size_t)n * sizeof(Professor), 1, fp);
    fclose(fp);

    profsCarregados = lerProfessoresDoArquivo("folha.dat", &qtdCarregada);
    printf("\n--- Professores carregados de folha.dat (%d) ---\n", qtdCarregada);
    for (i = 0; i < qtdCarregada; i++) {
        printf("Registro: %d | Horas aula: %d\n",
               profsCarregados[i].registro,
               profsCarregados[i].horas_aula);
    }

    free(profs);
    free(bufferBruto);
    free(profsCarregados);

    return 0;
}