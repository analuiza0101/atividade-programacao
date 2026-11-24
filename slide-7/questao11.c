#include <stdio.h>

#define QTD_ALUNOS 10

float calcularMediaTurma(float notas[], int qtd) {
    int i;
    float soma = 0.0;
    for (i = 0; i < qtd; i++) {
        soma += notas[i];
    }
    return soma / qtd;
}

float encontrarMaiorNota(float notas[], int qtd) {
    int i;
    float maior = notas[0];
    for (i = 1; i < qtd; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    return maior;
}

int contarAprovados(float notas[], int qtd) {
    int i, aprovados = 0;
    for (i = 0; i < qtd; i++) {
        if (notas[i] >= 7.0) {
            aprovados++;
        }
    }
    return aprovados;
}

void exibirResultados(float media, float maior, int aprovados) {
    printf("\n--- Resultados da Turma ---\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota registrada: %.2f\n", maior);
    printf("Quantidade de aprovados (>= 7.0): %d\n", aprovados);
}

int main() {
    float notas[QTD_ALUNOS];
    float media, maior;
    int aprovados, i;

    for (i = 0; i < QTD_ALUNOS; i++) {
        printf("Digite a nota final do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    media = calcularMediaTurma(notas, QTD_ALUNOS);
    maior = encontrarMaiorNota(notas, QTD_ALUNOS);
    aprovados = contarAprovados(notas, QTD_ALUNOS);

    exibirResultados(media, maior, aprovados);

    return 0;
}