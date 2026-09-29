#include <stdio.h>

int main()
{
    int saque;
    int n200, n100, n50, n20, n10, n5;
    int qtd200, qtd100, qtd50, qtd20, qtd10, qtd5;
    int total;

    printf("Digite a quantidade de notas de R$200: ");
    scanf("%d", &n200);

    printf("Digite a quantidade de notas de R$100: ");
    scanf("%d", &n100);

    printf("Digite a quantidade de notas de R$50: ");
    scanf("%d", &n50);

    printf("Digite a quantidade de notas de R$20: ");
    scanf("%d", &n20);

    printf("Digite a quantidade de notas de R$10: ");
    scanf("%d", &n10);

    printf("Digite a quantidade de notas de R$5: ");
    scanf("%d", &n5);

    printf("Digite o valor do saque: ");
    scanf("%d", &saque);

    if (saque <= 0)
    {
        printf("Valor de saque invalido.\n");
        return 0;
    }

    qtd200 = 0;
    qtd100 = 0;
    qtd50 = 0;
    qtd20 = 0;
    qtd10 = 0;
    qtd5 = 0;

    total = saque;


    while (total >= 200 && n200 > 1)
    {
        total = total - 200;
        qtd200++;
        n200--;
    }

    while (total >= 100 && n100 > 1)
    {
        total = total - 100;
        qtd100++;
        n100--;
    }

    while (total >= 50 && n50 > 1)
    {
        total = total - 50;
        qtd50++;
        n50--;
    }

    while (total >= 20 && n20 > 1)
    {
        total = total - 20;
        qtd20++;
        n20--;
    }

    while (total >= 10 && n10 > 1)
    {
        total = total - 10;
        qtd10++;
        n10--;
    }

    while (total >= 5 && n5 > 1)
    {
        total = total - 5;
        qtd5++;
        n5--;
    }

    if (total == 0)
    {
        printf("\nSaque realizado.\n");
        printf("Notas de R$200: %d\n", qtd200);
        printf("Notas de R$100: %d\n", qtd100);
        printf("Notas de R$50: %d\n", qtd50);
        printf("Notas de R$20: %d\n", qtd20);
        printf("Notas de R$10: %d\n", qtd10);
        printf("Notas de R$5: %d\n", qtd5);

        printf("Total de cedulas: %d\n",
               qtd200 + qtd100 + qtd50 + qtd20 + qtd10 + qtd5);
    }
    else
    {
        printf("Nao e possivel realizar o saque sem violar a regra.\n");
    }

    return 0;
}