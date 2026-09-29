#include <stdio.h>

int main()
{
    int a, b, c;
    int maior, lado1, lado2;

    printf("Digite o lado A: ");
    scanf("%d", &a);

    printf("Digite o lado B: ");
    scanf("%d", &b);

    printf("Digite o lado C: ");
    scanf("%d", &c);

    if (a + b > c && a + c > b && b + c > a)
    {

        if (a == b && b == c)
        {
            printf("Triangulo equilatero.\n");
        }
        else if (a == b || a == c || b == c)
        {
            printf("Triangulo isosceles.\n");
        }
        else
        {
            printf("Triangulo escaleno.\n");
        }

        if (a >= b && a >= c)
        {
            maior = a;
            lado1 = b;
            lado2 = c;
        }
        else if (b >= a && b >= c)
        {
            maior = b;
            lado1 = a;
            lado2 = c;
        }
        else
        {
            maior = c;
            lado1 = a;
            lado2 = b;
        }

        if (maior * maior == lado1 * lado1 + lado2 * lado2)
        {
            printf("Triangulo retangulo.\n");
        }
        else if (maior * maior < lado1 * lado1 + lado2 * lado2)
        {
            printf("Triangulo acutangulo.\n");
        }
        else
        {
            printf("Triangulo obtusangulo.\n");
        }
    }
    else
    {
        printf("Os valores nao formam um triangulo.\n");
    }

    return 0;
}