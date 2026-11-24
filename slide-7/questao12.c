#include <stdio.h>

#define QTD_PRODUTOS 8

int calcularTotalEstoque(int estoque[], int qtd) {
    int i, total = 0;
    for (i = 0; i < qtd; i++) {
        total += estoque[i];
    }
    return total;
}

int contarEstoqueBaixo(int estoque[], int qtd) {
    int i, baixo = 0;
    for (i = 0; i < qtd; i++) {
        if (estoque[i] < 5) {
            baixo++;
        }
    }
    return baixo;
}

int buscarProduto(int estoque[], int codigo) {
    if (codigo >= 1 && codigo <= QTD_PRODUTOS) {
        return codigo - 1;
    }
    return -1;
}

int main() {
    int estoque[QTD_PRODUTOS];
    int i, codigo_busca, indice;

    for (i = 0; i < QTD_PRODUTOS; i++) {
        printf("Digite a quantidade do produto (codigo %d): ", i + 1);
        scanf("%d", &estoque[i]);
    }

    printf("\nTotal em estoque: %d unidades\n", calcularTotalEstoque(estoque, QTD_PRODUTOS));
    printf("Produtos com estoque baixo (< 5): %d\n", contarEstoqueBaixo(estoque, QTD_PRODUTOS));

    printf("\nDigite o codigo do produto para buscar (1 a 8): ");
    scanf("%d", &codigo_busca);

    indice = buscarProduto(estoque, codigo_busca);
    if (indice != -1) {
        printf("Produto encontrado no indice %d (codigo %d) com %d unidades.\n",
               indice, codigo_busca, estoque[indice]);
    } else {
        printf("Produto nao encontrado (-1).\n");
    }

    return 0;
}