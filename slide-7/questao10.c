#include <stdio.h>

#define DIAS 5

float calcularTotal(float vendas[], int qtd) {
    int i;
    float total = 0.0;
    for (i = 0; i < qtd; i++) {
        total += vendas[i];
    }
    return total;
}

float calcularMedia(float total, int qtd) {
    return total / qtd;
}

int contarVendasAcimaDaMedia(float vendas[], int qtd, float media) {
    int i, contador = 0;
    for (i = 0; i < qtd; i++) {
        if (vendas[i] > media) {
            contador++;
        }
    }
    return contador;
}

int main() {
    float vendas[DIAS];
    float total, media;
    int dias_acima, i;

    for (i = 0; i < DIAS; i++) {
        printf("Digite o valor das vendas do dia %d: ", i + 1);
        scanf("%f", &vendas[i]);
    }

    total = calcularTotal(vendas, DIAS);
    media = calcularMedia(total, DIAS);
    dias_acima = contarVendasAcimaDaMedia(vendas, DIAS, media);

    printf("\nTotal vendido: R$ %.2f\n", total);
    printf("Media diaria: R$ %.2f\n", media);
    printf("Dias com vendas acima da media: %d\n", dias_acima);

    return 0;
}