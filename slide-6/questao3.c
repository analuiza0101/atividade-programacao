#include <stdio.h>

int main() {
    int tabela[3][3];
    int linha, coluna;

    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            printf("Digite o elemento da linha %d, coluna %d: ", linha, coluna);
            scanf("%d", &tabela[linha][coluna]);
        }
    }

    printf("\nMatriz 3x3:\n");
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            printf("%d", tabela[linha][coluna]);
            if (coluna < 2) {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}