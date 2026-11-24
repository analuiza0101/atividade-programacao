#include <stdio.h>

typedef struct {
    int conta_corrente;
    char nome[50];
    float saldo;
} Cliente;

int main() {
    FILE *fp;
    Cliente cli;
    int conta_alvo, encontrado = 0;
    float movimento;

    printf("Digite o numero da conta corrente: ");
    scanf("%d", &conta_alvo);
    printf("Digite o valor (positivo para deposito, negativo para saque): ");
    scanf("%f", &movimento);

    fp = fopen("clientes.bin", "rb+");
    if (fp == NULL) {
        printf("Erro ao abrir clientes.bin no modo \"rb+\".\n");
        return 1;
    }

    while (fread(&cli, sizeof(Cliente), 1, fp) == 1) {
        if (cli.conta_corrente == conta_alvo) {
            cli.saldo += movimento;
            fseek(fp, -(long)sizeof(Cliente), SEEK_CUR);
            fwrite(&cli, sizeof(Cliente), 1, fp);
            encontrado = 1;
            printf("Saldo atualizado com sucesso! Novo saldo de %s: R$ %.2f\n", cli.nome, cli.saldo);
            break;
        }
    }

    if (!encontrado) {
        printf("Conta corrente %d nao encontrada.\n", conta_alvo);
    }

    fclose(fp);
    return 0;
}