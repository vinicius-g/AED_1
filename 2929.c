#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} Pilha;

void pushPilha(Pilha **pilhaPresente, int diversao) {
    Pilha *presenteAtual = *pilhaPresente;
    Pilha *novoPresente = (Pilha*)malloc(sizeof(Pilha));

    novoPresente->valor = diversao;
    novoPresente->prox = presenteAtual;

    *pilhaPresente = novoPresente;
}

void popPilha(Pilha **pilhaPresente) {
    Pilha *presenteAtual = *pilhaPresente;

    if (presenteAtual == NULL) {
        printf("EMPTY\n");
        return;
    }

    *pilhaPresente = presenteAtual->prox;

    free(presenteAtual);
}

void minPilha(Pilha *pilhaPresente) {
    Pilha *presenteAtual = pilhaPresente;
    int menorValor;

    if (presenteAtual == NULL) {
        printf("EMPTY\n");
        return;
    }

    menorValor = presenteAtual->valor;

    while (presenteAtual != NULL) {
        if (presenteAtual->valor < menorValor) {
            menorValor = presenteAtual->valor;
        }
        presenteAtual = presenteAtual->prox;
    }

    printf("%d\n", menorValor);
}

void executar(Pilha **pilhaPresentes, char operacao[5]) {
    int diversao;

    if (strcmp(operacao, "PUSH") == 0) {
        scanf("%d", &diversao);
        pushPilha(pilhaPresentes, diversao);
        while(getchar() != '\n');
    }

    if (strcmp(operacao, "POP") == 0) {
        popPilha(pilhaPresentes);
    }

    if (strcmp(operacao, "MIN") == 0) {
        minPilha(*pilhaPresentes);
    }
}

void liberar(Pilha **pilhaPresentes) {
    Pilha *presenteAtual = *pilhaPresentes;

    while (presenteAtual != NULL) {
        *pilhaPresentes = presenteAtual->prox;
        free(presenteAtual);
        presenteAtual = *pilhaPresentes;
    }
}

int main () {
    Pilha *pilhaPresentes = NULL;
    int quantOperacoes;
    char operacao[6];

    scanf("%d", &quantOperacoes);
    while(getchar() != '\n');

    fgets(operacao, 6, stdin);
    operacao[strlen(operacao) - 1] = '\0';
    executar(&pilhaPresentes, operacao);

    quantOperacoes--;

    while (quantOperacoes) {
        fgets(operacao, 6, stdin);
        operacao[strlen(operacao) - 1] = '\0';
        executar(&pilhaPresentes, operacao);

        quantOperacoes--;
    }

    liberar(&pilhaPresentes);
}