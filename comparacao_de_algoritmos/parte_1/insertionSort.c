#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vetor[], int tamanho_vetor) {
    int i, j, item, min;

    for (i = 0; i < tamanho_vetor - 1; i++) {
        min = i;

        for (j = i + 1; j < tamanho_vetor; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        item = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = item;
    }
}

int main() {
    const int tamanho = 50000;
    int i, j, k, contagem_execucoes = 3, contagem_escala = 8;
    int vetor[tamanho * contagem_escala];
    clock_t inicio, fim;
    double tempo_gasto = 0, tempo_medio = 0;

    srand(time(NULL));

    for (i = 0; i < contagem_escala; i++) {
        printf("Tamanho do vetor: %d\n\n", (tamanho*i));

        for (j = 0; j < contagem_execucoes; j++) {
            for (k = 0; k < (tamanho * i); k++) {
                vetor[k] = rand() % 101;
            }

            inicio = clock();

            insertionSort(vetor, (tamanho * i));

            fim = clock();

            tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo_medio += tempo_gasto;

            printf("Tempo execucao %d: %f\n\n", j + 1, tempo_gasto);
        }

        tempo_medio /= contagem_execucoes;

        printf("Tempo medio: %f\n\n", tempo_medio);
    }
}
