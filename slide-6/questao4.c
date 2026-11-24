#include <stdio.h>

int main() {
    float tabela[3][4];
    int aluno, nota;

    for (aluno = 0; aluno < 3; aluno++) {
        for (nota = 0; nota < 3; nota++) {
            printf("Digite a nota %d do aluno %d: ", nota + 1, aluno + 1);
            scanf("%f", &tabela[aluno][nota]);
        }
        tabela[aluno][3] = (tabela[aluno][0] + tabela[aluno][1] + tabela[aluno][2]) / 3.0;
    }

    printf("\n%-8s %-8s %-8s %-8s %-8s\n", "Aluno", "nota1", "nota2", "nota3", "media");
    for (aluno = 0; aluno < 3; aluno++) {
        printf("Aluno%-3d %-8.1f %-8.1f %-8.1f %-8.1f\n",
               aluno + 1,
               tabela[aluno][0],
               tabela[aluno][1],
               tabela[aluno][2],
               tabela[aluno][3]);
    }

    return 0;
}