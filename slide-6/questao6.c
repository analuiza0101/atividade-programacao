#include <stdio.h>

int main() {
    int estoque[10];
    int i;
    int mais_de_20 = 0;
    int maior_qtd, produto_maior;

    for (i = 0; i < 10; i++) {
        printf("Digite a quantidade em estoque do produto %d: ", i + 1);
        scanf("%d", &estoque[i]);
    }

    printf("\n--- Quantidade de cada produto ---\n");
    for (i = 0; i < 10; i++) {
        printf("Produto %d: %d unidades\n", i + 1, estoque[i]);
    }

    printf("\n--- Produtos com estoque baixo (< 5) ---\n");
    for (i = 0; i < 10; i++) {
        if (estoque[i] < 5) {
            printf("Produto %d (%d unidades)\n", i + 1, estoque[i]);
        }
    }

    printf("\n--- Produtos esgotados (== 0) ---\n");
    for (i = 0; i < 10; i++) {
        if (estoque[i] == 0) {
            printf("Produto %d\n", i + 1);
        }
    }

    maior_qtd = estoque[0];
    produto_maior = 1;

    for (i = 0; i < 10; i++) {
        if (estoque[i] > 20) {
            mais_de_20++;
        }
        if (estoque[i] > maior_qtd) {
            maior_qtd = estoque[i];
            produto_maior = i + 1;
        }
    }

    printf("\nQuantidade de produtos com mais de 20 unidades: %d\n", mais_de_20);
    printf("Produto com maior quantidade em estoque: Produto %d (%d unidades)\n", produto_maior, maior_qtd);

    return 0;
}