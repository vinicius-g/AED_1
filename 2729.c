#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alocarMemoriaListas(int quantListas, char **listas, char ***listasOrganizadas) {
    int contador, contador_interno;

    for (contador = 0; contador < quantListas; contador++) {
        listas[contador] = (char *)malloc(21000 * sizeof(char));
        listasOrganizadas[contador] = (char **)malloc(1000 * sizeof(char *));

        for (contador_interno = 0; contador_interno < 1000; contador_interno++) {
            listasOrganizadas[contador][contador_interno] = (char *)malloc(21 * sizeof(char));
        }
    }
}

void liberarMemoriaListas(int quantListas, char **listas, char ***listasOrganizadas) {
    int contador, contador_interno;

    for (contador = 0; contador < quantListas; contador++) {
        for (contador_interno = 0; contador_interno < 1000; contador_interno++) {
            free(listasOrganizadas[contador][contador_interno]);
        }

        free(listas[contador]);
        free(listasOrganizadas[contador]);
    }

    free(listas);
    free(listasOrganizadas);
}

int verificarPalavraRepetida(int quantPalavras, char palavra[21], char **listasOrganizadas) {
    int contador_palavras = 0;

    for (contador_palavras = 0; contador_palavras < quantPalavras; contador_palavras++) {
        if (!strcmp(palavra, listasOrganizadas[contador_palavras])) {
            return 0;
        }
    }

    return 1;
}

void limparPalavra(int quantLetras, char palavra[21]) {
    int contador_letras;

    for (contador_letras = 0; contador_letras < quantLetras; contador_letras++) {
        palavra[contador_letras] = '\0';
    }
}

int compararItens(const void *item1, const void *item2) {
    return strcmp(*(const char **)item1, *(const char **)item2);
}

void lerListas(int quantListas, char **listas) {
    int contador;

    for (contador = 0; contador < quantListas; contador++) {
        scanf(" %[^\n]", listas[contador]);
        strcat(listas[contador], " ");
    }
}

void escreverListas(int quantPalavras, char **listasOrganizadas) {
    int contador_palavras;

    for (contador_palavras = 0; contador_palavras < quantPalavras; contador_palavras++) {
        printf("%s", listasOrganizadas[contador_palavras]);
        if (contador_palavras != quantPalavras - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int quant_listas, cont_listas, cont_letras, cont_letras_palavra, cont_palavras, palavra_repetida;
    char **listas, palavra[21], ***listas_organizadas;

    scanf("%d", &quant_listas);
    listas = (char **)malloc((size_t)quant_listas * sizeof(char *));
    listas_organizadas = (char ***)malloc((size_t)quant_listas * sizeof(char **));

    alocarMemoriaListas(quant_listas, listas, listas_organizadas);

    lerListas(quant_listas, listas);

    for (cont_listas = 0; cont_listas < quant_listas; cont_listas++) {
        cont_palavras = 0;
        cont_letras_palavra = 0;
        palavra_repetida = 1;

        for (cont_letras = 0; cont_letras < (int)strlen(listas[cont_listas]); cont_letras++) {
            palavra[cont_letras_palavra] = listas[cont_listas][cont_letras];

            if (listas[cont_listas][cont_letras] == ' ') {
                palavra[cont_letras_palavra] = '\0';

                palavra_repetida = verificarPalavraRepetida(cont_palavras, palavra, listas_organizadas[cont_listas]);

                if (palavra_repetida) {
                    strcpy(listas_organizadas[cont_listas][cont_palavras], palavra);
                    cont_palavras++;
                }

                limparPalavra(cont_letras_palavra, palavra);

                cont_letras_palavra = -1;
            }

            cont_letras_palavra++;
        }

        qsort(listas_organizadas[cont_listas], (size_t)cont_palavras, sizeof(char *), compararItens);

        escreverListas(cont_palavras, listas_organizadas[cont_listas]);
    }

    liberarMemoriaListas(quant_listas, listas, listas_organizadas);
}