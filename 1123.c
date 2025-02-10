#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void initMatriz(int ***matriz, int tamanho) {
    int i, j;

    *matriz = (int**)malloc(sizeof(int*) * tamanho);
    for (i = 0; i < tamanho; i++) {
        (*matriz)[i] = (int*)malloc(sizeof(int) * tamanho);
    }

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            (*matriz)[i][j] = INF;
        }
    }
}

void liberaMatriz(int **matriz, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int minDist(int distancias[], int visto[], int tamanho) {
    int min = INF, min_pos, i;

    for (i = 0; i < tamanho; i++) {
        if (!visto[i] && distancias[i] <= min) {
            min = distancias[i];
            min_pos = i;
        }
    }

    return min_pos;
}

int dijkstra(int **matrizAdjacencia, int tamanho, int destino, int origem) {
    int i, j, menorDist;
    int distancias[tamanho];
    int visto[tamanho];

    for (i = 0; i < tamanho; i++) {
        distancias[i] = INF;
        visto[i] = 0;
    }

    distancias[origem] = 0;

    for (i = 0; i < tamanho - 1; i++) {
        menorDist = minDist(distancias, visto, tamanho);
        visto[menorDist] = 1;

        if (menorDist < destino) {
            if (distancias[menorDist + 1] > distancias[menorDist] + matrizAdjacencia[menorDist][menorDist + 1]) {
                distancias[menorDist + 1] = distancias[menorDist] + matrizAdjacencia[menorDist][menorDist + 1];
            }

            continue;
        }

        for (j = 0; j < tamanho; j++) {
            if (!visto[j] && matrizAdjacencia[menorDist][j] != INF && distancias[menorDist] + matrizAdjacencia[menorDist][j] < distancias[j]) {
                distancias[j] = distancias[menorDist] + matrizAdjacencia[menorDist][j];
            }
        }
    }

    return distancias[destino];
}

int main() {
    int quantCidades, quantEstradas, quantCidadesRota, cidadeConserto, cidadeAtual, proxCidade, custoPedagio, custoTotal, i;
    int **matrizAdjacencia;

    while (scanf("%d %d %d %d", &quantCidades, &quantEstradas, &quantCidadesRota, &cidadeConserto) && quantCidades) {
        initMatriz(&matrizAdjacencia, quantCidades);

        for (i = 0; i < quantEstradas; i++) {
            scanf("%d", &cidadeAtual);
            scanf("%d", &proxCidade);
            scanf("%d", &custoPedagio);

            matrizAdjacencia[cidadeAtual][proxCidade] = custoPedagio;
            matrizAdjacencia[proxCidade][cidadeAtual] = custoPedagio;
        }

        custoTotal = dijkstra(matrizAdjacencia, quantCidades, quantCidadesRota - 1, cidadeConserto);
        printf("%d\n", custoTotal);
        liberaMatriz(matrizAdjacencia, quantCidades);
    }
}