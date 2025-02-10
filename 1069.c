#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diamantes {
    char pedaco[2];
    struct diamantes *prox;
} Pilha;

void pushPedaco(Pilha **extracao, char pedaco[2]) {
    Pilha *novoPedaco = (Pilha *)malloc(sizeof(Pilha));
    Pilha *pedacoAtual = *extracao;

    strncpy(novoPedaco->pedaco, pedaco, 2);
    novoPedaco->pedaco[1] = '\0';
    novoPedaco->prox = NULL;

    if (*extracao == NULL) {
        *extracao = novoPedaco;
    } else {
        while (pedacoAtual->prox != NULL) {
            pedacoAtual = pedacoAtual->prox;
        }

        pedacoAtual->prox = novoPedaco;
    }
}

void popPedaco(Pilha **extracao) {
    Pilha *pedacoAtual = *extracao;

    if (*extracao == NULL) return;

    if (pedacoAtual->prox == NULL) {
        free(pedacoAtual);

        *extracao = NULL;
        return;
    }

    *extracao = pedacoAtual->prox;
    free(pedacoAtual);
}

void limparPilha(Pilha **extracao) {
    Pilha *pedacoAtual = *extracao;


    if (*extracao == NULL) return;

    if (pedacoAtual->prox == NULL) {
        free(pedacoAtual);

        *extracao = NULL;
        return;
    }

    while (pedacoAtual->prox != NULL) {
        *extracao = pedacoAtual->prox;

        free(pedacoAtual);

        pedacoAtual = *extracao;
    }

    free(pedacoAtual);

    *extracao = NULL;
}

int main() {
    char extracao_bruta[1000], pedaco[2];
    int quant_extracoes, quant_diamantes, cont;
    Pilha *extracao = NULL;

    scanf("%d", &quant_extracoes);

    while (quant_extracoes > 0) {
        quant_diamantes = 0;
        scanf(" %[^\n]", extracao_bruta);

        for (cont = 0; cont < (int)strlen(extracao_bruta); cont++) {
            pedaco[0] = extracao_bruta[cont];
            pedaco[1] = '\0';
            if (extracao_bruta[cont] == '<') {
                pushPedaco(&extracao, pedaco);
            }

            if (extracao_bruta[cont] == '>' && extracao != NULL) {
                popPedaco(&extracao);
                quant_diamantes++;
            }
        }

        printf("%d\n", quant_diamantes);

        limparPilha(&extracao);
        quant_extracoes--;
    }
}