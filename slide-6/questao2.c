#include <stdio.h>

int main() {
    float medias[30];
    char nomes[30][100];
    int contador;

    for (contador = 0; contador < 30; contador++) {
        printf("Digite o nome do aluno %d: ", contador + 1);
        scanf("%s", nomes[contador]);

        printf("Digite a media do aluno %d: ", contador + 1);
        scanf("%f", &medias[contador]);
    }

    printf("\n--- Lista de Alunos e Medias ---\n");
    for (contador = 0; contador < 30; contador++) {
        printf("Aluno: %s | Media: %.2f\n", nomes[contador], medias[contador]);
    }

    return 0;
}