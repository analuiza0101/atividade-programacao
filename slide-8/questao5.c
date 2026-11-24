#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QTD_PART 4

double fatorialDouble(int n) {
    double fat = 1.0;
    int i;
    if (n < 0) return 0.0;
    for (i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

double potenciaDouble(double base, int exp) {
    double res = 1.0;
    int i;
    for (i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

double calcularMediaPonderada(float *linha, int qtd) {
    int i;
    double somaPond = 0.0, somaPesos = 0.0;
    for (i = 0; i < qtd; i++) {
        double peso = (double)(i + 1);
        somaPond += linha[i] * peso;
        somaPesos += peso;
    }
    if (somaPesos == 0.0) return 0.0;
    return somaPond / somaPesos;
}

int main() {
    char nomes[QTD_PART][100];
    int idades[QTD_PART];
    double ids[QTD_PART];
    int qtdVals[QTD_PART];

    float **mat = (float **)malloc(sizeof(float *) * QTD_PART);
    int i, j, k;

    /* Para diagonal do retangulo: dois primeiros valores >= 0 na ordem de entrada */
    int achouLado1 = 0, achouLado2 = 0;
    double lado1 = 0.0, lado2 = 0.0;
    int temDiagonal = 0;
    double diagonal = 0.0;

    for (i = 0; i < QTD_PART; i++) {
        printf("Participante %d - Nome: ", i + 1);
        scanf("%99s", nomes[i]);
        printf("Participante %d - Idade: ", i + 1);
        scanf("%d", &idades[i]);
        ids[i] = fatorialDouble(idades[i]) / 2.0;
    }

    for (i = 0; i < QTD_PART; i++) {
        printf("Quantidade de valores para %s: ", nomes[i]);
        scanf("%d", &qtdVals[i]);

        mat[i] = (float *)malloc(sizeof(float) * (qtdVals[i] > 0 ? qtdVals[i] : 1));
        for (j = 0; j < qtdVals[i]; j++) {
            printf("  Valor %d de %s: ", j + 1, nomes[i]);
            scanf("%f", &mat[i][j]);

            if (mat[i][j] >= 0.0f) {
                if (!achouLado1) {
                    lado1 = (double)mat[i][j];
                    achouLado1 = 1;
                } else if (!achouLado2) {
                    lado2 = (double)mat[i][j];
                    achouLado2 = 1;
                }
            }
        }
    }

    /* Garante IDs unicos */
    int duplicado;
    do {
        duplicado = 0;
        for (i = 0; i < QTD_PART; i++) {
            for (j = i + 1; j < QTD_PART; j++) {
                if (ids[i] == ids[j]) {
                    duplicado = 1;
                    ids[i] = potenciaDouble(fatorialDouble(idades[i] / 2), qtdVals[i]);
                    ids[j] = potenciaDouble(fatorialDouble(idades[j] / 2), qtdVals[j]);
                }
            }
        }
    } while (duplicado);

    /* Ordena participantes em ordem alfabetica mantendo IDs e linhas da matriz */
    for (i = 0; i < QTD_PART - 1; i++) {
        for (j = i + 1; j < QTD_PART; j++) {
            if (strcmp(nomes[j], nomes[i]) < 0) {
                char tmpNome[100];
                int tmpIdade, tmpQtd;
                double tmpId;
                float *tmpLinha;

                strcpy(tmpNome, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], tmpNome);

                tmpIdade = idades[i];
                idades[i] = idades[j];
                idades[j] = tmpIdade;

                tmpId = ids[i];
                ids[i] = ids[j];
                ids[j] = tmpId;

                tmpQtd = qtdVals[i];
                qtdVals[i] = qtdVals[j];
                qtdVals[j] = tmpQtd;

                tmpLinha = mat[i];
                mat[i] = mat[j];
                mat[j] = tmpLinha;
            }
        }
    }

    if (achouLado1 && achouLado2) {
        diagonal = sqrt(lado1 * lado1 + lado2 * lado2);
        temDiagonal = 1;
    } else {
        printf("\nNao foi possivel calcular a diagonal do retangulo (menos de dois valores nao negativos).\n");
    }

    printf("\n========== CLASSIFICACAO FINAL ==========\n");
    for (i = 0; i < QTD_PART; i++) {
        double mp = calcularMediaPonderada(mat[i], qtdVals[i]);
        printf("%-15s", nomes[i]);
        if (!temDiagonal) {
            printf("SEM DIAGONAL\n");
        } else if (mp > diagonal) {
            printf("ACIMA DA DIAGONAL\n");
        } else if (mp < diagonal) {
            printf("ABAIXO DA DIAGONAL\n");
        } else {
            printf("SOBRE A DIAGONAL\n");
        }
    }

    for (i = 0; i < QTD_PART; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}