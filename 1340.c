#include <stdio.h>
#include <stdlib.h>

typedef struct valor {
    int num;
    struct valor *prox;
} Valores;

typedef struct lista {
    Valores *inicio;
    Valores *fim;
} Lista;

void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void pushValor(int valor, Lista *lista) {
    Valores *novoValor = (Valores *)malloc(sizeof(Valores));
    novoValor->num = valor;
    novoValor->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoValor;
    } else {
        lista->fim->prox = novoValor;
    }

    lista->fim = novoValor;
}

int testarFila(int valor, Lista *lista) {
    Valores *valorAtual = lista->inicio;

    if (lista->inicio == NULL) return 0;

    if (valorAtual->num != valor) {
        return 0;
    } else {
        lista->inicio = valorAtual->prox;
        if (lista->inicio == NULL) {
            lista->fim = NULL;
        }

        free(valorAtual);
    }

    return 1;
}

int testarPilha(int valor, Lista *lista) {
    Valores *valorAtual = lista->inicio;
    Valores *valorAnterior = NULL;

    if (lista->inicio == NULL) return 0;

    while (valorAtual->prox != NULL) {
        valorAnterior = valorAtual;
        valorAtual = valorAtual->prox;
    }

    if (valorAtual->num != valor) {
        return 0;
    } else {
        if (valorAnterior == NULL) {
            lista->inicio = NULL;
            lista->fim = NULL;
        } else {
            valorAnterior->prox = NULL;
            lista->fim = valorAnterior;
        }
        free(valorAtual);
    }

    return 1;
}

int testarHeap(int valor, Lista *lista) {
    Valores *valorAnterior = NULL, *valorAtual = lista->inicio;
    Valores *maiorValor = lista->inicio, *maiorAnterior = NULL;

    if (lista->inicio == NULL) return 0;

    while (valorAtual != NULL) {
        if (valorAtual->num > maiorValor->num) {
            maiorValor = valorAtual;
            maiorAnterior = valorAnterior;
        }

        valorAnterior = valorAtual;
        valorAtual = valorAtual->prox;
    }

    if (maiorValor->num != valor) {
        return 0;
    } else {
        if (maiorAnterior == NULL) {
            lista->inicio = maiorValor->prox;
        } else {
            maiorAnterior->prox = maiorValor->prox;
        }
        if (lista->fim == maiorValor) {
            lista->fim = maiorAnterior;
        }
        free(maiorValor);
    }

    return 1;
}

void liberarValores(Lista *lista) {
    Valores *valorAtual = lista->inicio;
    Valores *remover = valorAtual;

    while (valorAtual != NULL) {
        remover = valorAtual;
        valorAtual = valorAtual->prox;
        free(remover);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
}

int main() {
    Lista fila, pilha, heap;
    int quantValores, novoValor, comando, i;
    int filaOk, pilhaOk, heapOk, estrutura;

    while (scanf("%d", &quantValores) != EOF) {
        inicializarLista(&fila);
        inicializarLista(&pilha);
        inicializarLista(&heap);

        filaOk = 1;
        pilhaOk = 1;
        heapOk = 1;
        estrutura = 0;

        for (i = 0; i < quantValores; i++) {
            scanf("%d %d", &comando, &novoValor);

            if (comando == 1) {
                pushValor(novoValor, &fila);
                pushValor(novoValor, &pilha);
                pushValor(novoValor, &heap);
            } else {
                if (filaOk) filaOk = testarFila(novoValor, &fila);
                if (pilhaOk) pilhaOk = testarPilha(novoValor, &pilha);
                if (heapOk) heapOk = testarHeap(novoValor, &heap);
            }
        }

        if (filaOk + pilhaOk + heapOk > 1) {
            printf("not sure\n");
        } else if (filaOk) {
            printf("queue\n");
        } else if (pilhaOk) {
            printf("stack\n");
        } else if (heapOk) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }

        liberarValores(&fila);
        liberarValores(&pilha);
        liberarValores(&heap);
    }
}
