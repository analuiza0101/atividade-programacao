#include <stdio.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

void verificarSituacao(float media) {
    printf("Media: %.2f\n", media);
    if (media >= 7.0) {
        printf("Situacao: Aprovado\n");
    } else {
        printf("Situacao: Reprovado\n");
    }
}

int main() {
    float nota1, nota2, nota3, media;

    printf("Digite as tres notas: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    media = calcularMedia(nota1, nota2, nota3);
    verificarSituacao(media);

    return 0;
}