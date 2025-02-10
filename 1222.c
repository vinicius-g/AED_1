#include <stdio.h>
#include <string.h>

int main() {
    int quantPalavras, maxLinhas, maxCaracLinha, paginasUsadas, i, tamPalavra, linhaAtual, linhasUsadas;
    char palavra[71];

    while (scanf("%d %d %d", &quantPalavras, &maxLinhas, &maxCaracLinha) != EOF) {
        paginasUsadas = 1;
        linhasUsadas = 1;
        linhaAtual = 0;

        for (i = 0; i < quantPalavras; i++) {
            scanf("%s", palavra);
            tamPalavra = (int)strlen(palavra);

            linhaAtual += tamPalavra + 1;
            if (linhaAtual == tamPalavra + 1) linhaAtual--;
            if (linhaAtual > maxCaracLinha) {
                linhasUsadas++;
                linhaAtual = tamPalavra;
            }

            if (linhasUsadas > maxLinhas) {
                linhasUsadas = 1;
                paginasUsadas++;
            }
        }

        printf("%d\n", paginasUsadas);
    }
}