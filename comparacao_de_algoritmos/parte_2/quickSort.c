#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separaVetor(int inicio, int fim, int vetor[]) {
    int pivo, contadorMeio, contador, aux;

    pivo = vetor[fim];
    contadorMeio = inicio;

    for (contador = inicio; contador < fim; contador++) {
        if (vetor[contador] <= pivo) {
            aux = vetor[contadorMeio];
            vetor[contadorMeio] = vetor[contador];
            vetor[contador] = aux;

            contadorMeio++;
        }
    }

    vetor[fim] = vetor[contadorMeio];
    vetor[contadorMeio] = pivo;

    return contadorMeio;
}

void quickSort(int inicio, int fim, int vetor[]) {
    int meio;

    if (inicio < fim) {
        meio = separaVetor(inicio, fim, vetor);

        quickSort(inicio, meio - 1, vetor);
        quickSort(meio + 1, fim, vetor);
    }
}

int main() {
    const int tamanho = 20000;
    int i, j, k, contagem_execucoes = 3, contagem_testes = 20;
    int vetor[tamanho * contagem_testes];
    clock_t inicio, fim;
    double tempo_gasto = 0, tempo_medio = 0;

    srand(time(NULL));

    for (i = 1; i <= contagem_testes; i++) {
        printf("Tamanho do vetor: %d\n\n", (tamanho*i));
        tempo_medio = 0;

        for (j = 0; j < contagem_execucoes; j++) {
            for (k = 0; k < (tamanho*i); k++) {
                vetor[k] = rand() % 101;
            }

            inicio = clock();

            quickSort(0, (tamanho * i), vetor);

            fim = clock();

            tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo_medio += tempo_gasto;

            printf("Tempo execucao %d: %f\n", j + 1, tempo_gasto);
        }

        tempo_medio /= contagem_execucoes;

        printf("\nTempo medio: %f\n\n", tempo_medio);
    }
}
