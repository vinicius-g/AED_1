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
    const int tamanho_vetor = 20000;
    int i, j, k, execucoes = 3, testes = 20;
    int vetor[tamanho_vetor * testes];
    clock_t inicio, fim;
    double tempo_gasto = 0, tempo_medio = 0;

    srand(time(NULL));

    for (i = 1; i <= testes; i++) {
        printf("Tamanho do vetor: %d\n\n", (tamanho_vetor*i));
        tempo_medio = 0;

        for (j = 0; j < execucoes; j++) {
            for (k = 0; k < (tamanho_vetor * i); k++) {
                vetor[k] = rand() % 101;
            }

            inicio = clock();

            insertionSort(vetor, (tamanho_vetor * i));

            fim = clock();

            tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo_medio += tempo_gasto;

            printf("Tempo execucao %d: %f\n", j + 1, tempo_gasto);
        }

        tempo_medio /= execucoes;

        printf("\nTempo medio: %f\n\n", tempo_medio);
    }
}
