#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[12];
    int zona;
} Eleitor;

typedef struct {
    Eleitor eleitor;
    int numero_voto;
} Cedula;

Cedula *adicionarVoto(Cedula *votos, int *qtd, Cedula novoVoto) {
    Cedula *temp = (Cedula *)realloc(votos, (size_t)(*qtd + 1) * sizeof(Cedula));
    if (temp == NULL) {
        printf("Erro ao realocar memoria para novo voto.\n");
        return votos;
    }
    votos = temp;
    votos[*qtd] = novoVoto;
    (*qtd)++;
    return votos;
}

int salvarUrnas(const char *nomeArquivo, Cedula *votos, int qtd) {
    FILE *fp = fopen(nomeArquivo, "wb");
    if (fp == NULL) {
        return 0;
    }
    if (qtd > 0) {
        fwrite(votos, sizeof(Cedula), (size_t)qtd, fp);
    }
    fclose(fp);
    return 1;
}

Cedula *recuperarUrnasRapido(const char *nomeArquivo, int *qtdRecuperada) {
    FILE *fp = fopen(nomeArquivo, "rb");
    long tamanhoBytes;
    int n;
    Cedula *bloco;

    *qtdRecuperada = 0;
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    tamanhoBytes = ftell(fp);
    rewind(fp);

    if (tamanhoBytes <= 0) {
        fclose(fp);
        return NULL;
    }

    n = (int)(tamanhoBytes / (long)sizeof(Cedula));
    bloco = (Cedula *)malloc((size_t)n * sizeof(Cedula));
    if (bloco == NULL) {
        fclose(fp);
        return NULL;
    }

    if (fread(bloco, sizeof(Cedula), (size_t)n, fp) != (size_t)n) {
        free(bloco);
        fclose(fp);
        return NULL;
    }

    *qtdRecuperada = n;
    fclose(fp);
    return bloco;
}

int main() {
    Cedula *votos = NULL;
    int qtdVotos = 0, i, qtdLidos = 0;
    char continuar;
    Cedula *votosRecuperados;

    do {
        Cedula c;
        printf("Titulo do eleitor: ");
        scanf("%11s", c.eleitor.titulo);
        printf("Zona eleitoral: ");
        scanf("%d", &c.eleitor.zona);
        printf("Numero do voto: ");
        scanf("%d", &c.numero_voto);

        votos = adicionarVoto(votos, &qtdVotos, c);

        printf("Registrar outro voto? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    if (salvarUrnas("urnas.bin", votos, qtdVotos)) {
        printf("\nVotos salvos em urnas.bin.\n");
    } else {
        printf("\nErro ao salvar urnas.bin.\n");
    }

    votosRecuperados = recuperarUrnasRapido("urnas.bin", &qtdLidos);
    printf("\n--- Votos recuperados de urnas.bin (%d) ---\n", qtdLidos);
    for (i = 0; i < qtdLidos; i++) {
        printf("Titulo: %s | Zona: %d | Voto: %d\n",
               votosRecuperados[i].eleitor.titulo,
               votosRecuperados[i].eleitor.zona,
               votosRecuperados[i].numero_voto);
    }

    free(votos);
    free(votosRecuperados);

    return 0;
}