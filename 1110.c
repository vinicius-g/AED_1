#include <stdio.h>
#include <stdlib.h>

typedef struct card {
    int num;
    struct card *prox;
} Pilha;

void pushPilha(Pilha **pilhaCartas, int num) {
    Pilha *novaCarta = (Pilha*)malloc(sizeof(Pilha));
    Pilha *atual = *pilhaCartas;

    novaCarta->num = num;
    novaCarta->prox = atual;

    *pilhaCartas = novaCarta;
}

int popPilha(Pilha **pilhaCartas) {
    Pilha *atual = *pilhaCartas;
    int num = atual->num;

    *pilhaCartas = atual->prox;
    free(atual);
    return num;
}

void porNoFinal(Pilha **pilhaCartas) {
    Pilha *primeiro = *pilhaCartas;
    Pilha *atual = primeiro->prox;

    if (primeiro->prox == NULL) return;

    *pilhaCartas = atual;
    primeiro->prox = NULL;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = primeiro;
}

int main() {
    int quantCartas, *descartadas, i;
    Pilha *pilhaCartas = NULL;

    scanf("%d", &quantCartas);
    descartadas = (int*)malloc(sizeof(int) * quantCartas - 1);

    while (quantCartas != 0) {
        for (i = quantCartas; i > 0; i--) {
            pushPilha(&pilhaCartas, i);
        }
        printf("Discarded cards: ");
        for (i = 0; i < quantCartas - 1; i++) {
            printf("%d", popPilha(&pilhaCartas));
            if (i != quantCartas - 2) printf(", ");
            porNoFinal(&pilhaCartas);
        }
        printf("\n");
        printf("Remaining card: %d\n", popPilha(&pilhaCartas));

        scanf("%d", &quantCartas);
        descartadas = (int*)realloc(descartadas, sizeof(int) * quantCartas - 1);
    }
}