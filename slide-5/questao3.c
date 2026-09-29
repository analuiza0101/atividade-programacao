#include <stdio.h>

int main()
{
    float moeda;
    float total = 0;
    char continuar;

    do
    {
        printf("Digite o valor da moeda (0.50, 1.00 ou 2.00): ");
        scanf("%f", &moeda);

        if (moeda == 0.50 || moeda == 1.00 || moeda == 2.00)
        {
            total = total + moeda;
            printf("Moeda adicionada!\n");
        }
        else
        {
            printf("Moeda invalida!\n");
        }

        printf("Deseja adicionar outra moeda? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    printf("\nTotal acumulado: R$ %.2f\n", total);

    return 0;
}