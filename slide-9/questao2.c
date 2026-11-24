#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char cargo[30];
    float salario;
} Funcionario;

int main() {
    Funcionario *original = (Funcionario *)malloc(sizeof(Funcionario));
    Funcionario *backup = (Funcionario *)malloc(sizeof(Funcionario));
    FILE *fp;

    if (original == NULL || backup == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(original);
        free(backup);
        return 1;
    }

    printf("Digite o ID do funcionario: ");
    scanf("%d", &original->id);
    printf("Digite o cargo (sem espacos): ");
    scanf("%29s", original->cargo);
    printf("Digite o salario: ");
    scanf("%f", &original->salario);

    memcpy(backup, original, sizeof(Funcionario));

    fp = fopen("backup_rh.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir backup_rh.bin para escrita.\n");
        free(original);
        free(backup);
        return 1;
    }

    fwrite(backup, sizeof(Funcionario), 1, fp);
    fclose(fp);

    printf("\nDados espelhados e salvos em backup_rh.bin com sucesso.\n");

    free(original);
    free(backup);
    original = NULL;
    backup = NULL;

    return 0;
}