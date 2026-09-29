#include <stdio.h>

int main()
{
    float consumo;
    float soma = 0;
    float media;

    for (int i = 1; i <= 5; i++)
    {
        printf("Digite o consumo do morador %d: ", i);
        scanf("%f", &consumo);

        soma = soma + consumo;

        if (consumo <= 20)
        {
            printf("Consumo dentro da media.\n");
        }
        else
        {
            printf("Consumo acima da media.\n");
        }
    }

    media = soma / 5;

    printf("\nConsumo medio geral: %.2f m3\n", media);

    return 0;
}