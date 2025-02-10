#include <stdio.h>
#include <string.h>

int main() {
    int quantPalavras, tamPalavra, mediaTam, i, palavraValida;
    char enunciado[51];

    while (scanf(" %[^\n]", enunciado) != EOF) {
        palavraValida = 1;
        quantPalavras = 0;
        tamPalavra = 0;
        mediaTam = 0;

        for (i = 0; i < (int)strlen(enunciado); i++) {
            if ((enunciado[i] >= 48 && enunciado[i] <= 57) || (enunciado[i] == 46 && enunciado[i + 1] != '\0')) {
                palavraValida = 0;
                tamPalavra = 0;
            }

            if (((enunciado[i] >= 65 && enunciado[i] <= 90) || (enunciado[i] >= 97 && enunciado[i] <= 122)) && palavraValida) {
                tamPalavra++;
            }

            if (enunciado[i] == 32 || enunciado[i + 1] == '\0') {
                if (tamPalavra > 0) {
                    mediaTam += tamPalavra;
                    quantPalavras++;
                    tamPalavra = 0;
                    palavraValida = 1;
                } else {
                    tamPalavra = 0;
                    palavraValida = 1;
                }
            }
        }

        if (quantPalavras != 0) {
            mediaTam /= quantPalavras;
        } else {
            mediaTam = 0;
        }

        if (mediaTam <= 3) {
            printf("250\n");
        } else if (mediaTam > 3 && mediaTam < 6) {
            printf("500\n");
        } else {
            printf("1000\n");
        }
    }
}