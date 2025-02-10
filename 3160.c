#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct amigo {
    char nome[50];
    struct amigo *prox;
} Amigos;

void adicionarAmigo(Amigos **listaAmigos, char *nomeAmigo) {
    Amigos *novoAmigo = (Amigos*)malloc(sizeof(Amigos));
    Amigos *amigoAtual = *listaAmigos;

    strncpy(novoAmigo->nome, nomeAmigo, sizeof(novoAmigo->nome) - 1);
    novoAmigo->nome[sizeof(novoAmigo->nome) - 1] = '\0';
    novoAmigo->prox = NULL;

    while(amigoAtual->prox != NULL) {
        amigoAtual = amigoAtual->prox;
    }

    amigoAtual->prox = novoAmigo;
}

void adicionarAmigoAntes(Amigos **listaAmigos, char *nomeAmigo, char *nomeProcurado) {
    Amigos *novoAmigo = (Amigos*)malloc(sizeof(Amigos));
    Amigos *amigoAnterior = *listaAmigos;
    Amigos *amigoAtual = *listaAmigos;

    strncpy(novoAmigo->nome, nomeAmigo, sizeof(novoAmigo->nome) - 1);
    novoAmigo->nome[sizeof(novoAmigo->nome) - 1] = '\0';
    novoAmigo->prox = NULL;

    while(strcmp(amigoAtual->nome, nomeProcurado) && amigoAtual->prox != NULL) {
        amigoAnterior = amigoAtual;
        amigoAtual = amigoAtual->prox;
    }

    if (!strcmp(amigoAtual->nome, nomeProcurado)) {
        novoAmigo->prox = amigoAtual;
        amigoAnterior->prox = novoAmigo;
    } else {
        amigoAtual->prox = novoAmigo;
    }
}

void imprimirAmigos(Amigos *amigoAtual) {
    while (amigoAtual != NULL) {
        printf("%s", amigoAtual->nome);
        if (amigoAtual->prox != NULL) {
            printf(" ");
        }
        amigoAtual = amigoAtual->prox;
    }
    printf("\n");
}

int main() {
    Amigos *lista_amigos = (Amigos*)malloc(sizeof(Amigos));
    lista_amigos->nome[0] = '\0';
    lista_amigos->prox = NULL;
    char amigos_iniciais[1000], novos_amigos[1000], amigo_procurado[50], *amigo;

    scanf(" %[^\n]", amigos_iniciais);
    scanf(" %[^\n]", novos_amigos);
    scanf(" %[^\n]", amigo_procurado);

    amigo = strtok(amigos_iniciais, " ");

    while (amigo != NULL) {
        adicionarAmigo(&lista_amigos, amigo);
        amigo = strtok(NULL, " ");
    }

    amigo = strtok(novos_amigos, " ");

    while (amigo != NULL) {
        adicionarAmigoAntes(&lista_amigos, amigo, amigo_procurado);
        amigo = strtok(NULL, " ");
    }

    imprimirAmigos(lista_amigos->prox);
}