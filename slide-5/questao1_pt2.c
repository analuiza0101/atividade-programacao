#include <stdio.h>

int main() {
    int i, num;
    int pares = 0, impares = 0;

    for (i = 1; i <= 10; i++) {
        printf("Digite o %do numero inteiro: ", i);
        scanf("%d", &num);

        if (num % 2 == 0) {
            printf("O numero %d eh PAR.\n", num);
            pares++;
        } else {
            printf("O numero %d eh IMPAR.\n", num);
            impares++;
        }
    }

    printf("\nQuantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);

    return 0;
}
