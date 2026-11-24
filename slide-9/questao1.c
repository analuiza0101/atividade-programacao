#include <stdio.h>

#define QTD_PRODUTOS 3

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

int main() {
    Produto itens[QTD_PRODUTOS];
    FILE *fp;
    int i;

    for (i = 0; i < QTD_PRODUTOS; i++) {
        printf("--- Produto %d ---\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &itens[i].codigo);
        printf("Nome (sem espacos): ");
        scanf("%49s", itens[i].nome);
        printf("Preco: ");
        scanf("%f", &itens[i].preco);
    }

    fp = fopen("estoque.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir estoque.txt para escrita.\n");
        return 1;
    }

    for (i = 0; i < QTD_PRODUTOS; i++) {
        fprintf(fp, "%d %s %.2f\n", itens[i].codigo, itens[i].nome, itens[i].preco);
    }
    fclose(fp);

    fp = fopen("estoque.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir estoque.txt para leitura.\n");
        return 1;
    }

    printf("\n+--------+------------------------------------+------------+\n");
    printf("| Codigo | Nome                               | Preco (R$) |\n");
    printf("+--------+------------------------------------+------------+\n");

    Produto lido;
    while (fscanf(fp, "%d %49s %f", &lido.codigo, lido.nome, &lido.preco) == 3) {
        printf("| %-6d | %-34s | %10.2f |\n", lido.codigo, lido.nome, lido.preco);
    }

    printf("+--------+------------------------------------+------------+\n");
    fclose(fp);

    return 0;
}