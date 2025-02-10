#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    int prioridade;
    int chegada;
    char id[6];
    struct cel *prox;
} Aviao;

typedef struct infos {
        char id[6];
        int cardealidade;
        int chegada[4];
} infosVoo;

void push(Aviao **voos, infosVoo infos) {
    Aviao *vooAnterior = NULL;
    Aviao *vooAtual = *voos;
    Aviao *novoVoo = (Aviao*)malloc(sizeof(Aviao));

    novoVoo->prioridade = infos.cardealidade;
    novoVoo->chegada = infos.chegada[infos.cardealidade - 1];
    strcpy(novoVoo->id, infos.id);
    novoVoo->prox = NULL;

    if (vooAtual == NULL) {
        *voos = novoVoo;
        return;
    }

    if (novoVoo->prioridade < vooAtual->prioridade) {
        novoVoo->prox = vooAtual;
        *voos = novoVoo;
        return;
    }

    while (vooAtual != NULL && novoVoo->chegada >= vooAtual->chegada) {
        if (novoVoo->chegada == vooAtual->chegada && novoVoo->prioridade < vooAtual->prioridade) break;
        vooAnterior = vooAtual;
        vooAtual = vooAtual->prox;
    }

    if (vooAtual == NULL) {
        if (novoVoo->chegada > vooAnterior->chegada) {
            vooAnterior->prox = novoVoo;
            return;
        }
    }

    novoVoo->prox = vooAtual;
    vooAnterior->prox = novoVoo;
}

void imprimirIdVoos(Aviao *voos) {
    Aviao *vooAtual = voos;

    if (vooAtual == NULL) return;

    while (vooAtual->prox != NULL) {
        printf("%s ", vooAtual->id);
        vooAtual = vooAtual->prox;
    }
    printf("%s\n", vooAtual->id);
}

void liberarMemoria(Aviao **voos) {
    Aviao *vooAtual = *voos;
    Aviao *vooAnterior;

    while (vooAtual->prox != NULL) {
        vooAnterior = vooAtual;
        vooAtual = vooAtual->prox;
        free(vooAnterior);
    }

    free(vooAtual);
    *voos = NULL;
}

int main() {
    infosVoo infoVoo;
    char info[6];
    int i;
    Aviao *voos = NULL;

    for (i = 0; i < 4; i++) {
        infoVoo.chegada[i] = 0;
    }

    fgets(info, 6, stdin);
    info[strlen(info) - 1] = '\0';

    switch (info[1]) {
        case '1':
            infoVoo.cardealidade = 1;
            break;
        case '2':
            infoVoo.cardealidade = 3;
            break;
        case '3':
            infoVoo.cardealidade = 2;
            break;
        case '4':
            infoVoo.cardealidade = 4;
            break;
    }

    while (infoVoo.cardealidade != 0) {
        fgets(info, 6, stdin);
        info[strlen(info) - 1] = '\0';

        if (info[0] == '-' || info[0] == '0') {
            switch (info[1]) {
                case '1':
                    infoVoo.cardealidade = 1;
                    break;
                case '2':
                    infoVoo.cardealidade = 3;
                    break;
                case '3':
                    infoVoo.cardealidade = 2;
                    break;
                case '4':
                    infoVoo.cardealidade = 4;
                    break;
                default:
                    infoVoo.cardealidade = 0;
                    break;
            }
            continue;
        }
        strcpy(infoVoo.id, info);
        push(&voos, infoVoo);
        infoVoo.chegada[infoVoo.cardealidade - 1]++;
    }

    imprimirIdVoos(voos);
    liberarMemoria(&voos);
}