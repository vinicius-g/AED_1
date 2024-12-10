#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int inicio, int meio, int fim, int vetor[]) {
    int inicioContador, meioContador, contador, *vetor_temporario;

    vetor_temporario = (int*)malloc(sizeof(int) * (fim - inicio));

    inicioContador = inicio;
    meioContador = meio;
    contador = 0;

    while (inicioContador < meio && meioContador < fim) {
        if (vetor[inicioContador] < vetor[meioContador]) {
            vetor_temporario[contador++] = vetor[inicioContador++];
        } else {
            vetor_temporario[contador++] = vetor[meioContador++];
        }
    }

    while (inicioContador < meio) {
        vetor_temporario[contador++] = vetor[inicioContador++];
    }

    while (meioContador < fim) {
        vetor_temporario[contador++] = vetor[meioContador++];
    }

    for (inicioContador = inicio; inicioContador < fim; inicioContador++) {
        vetor[inicioContador] = vetor_temporario[inicioContador - inicio];
    }

    free(vetor_temporario);
}

void mergeSort(int inicio, int fim, int vetor[]) {
    if (inicio < fim - 1) {
        int meio = (inicio + fim)/2;

        mergeSort(inicio, meio, vetor);
        mergeSort(meio, fim, vetor);
        intercala(inicio, meio, fim, vetor);
    }
}

int main() {
    const int tamanho = 20000;
    int i, j, k, contagem_execucoes = 3, contagem_escala = 20;
    int vetor[tamanho * contagem_escala];
    clock_t inicio, fim;
    double tempo_gasto = 0, tempo_medio = 0;

    srand(time(NULL));

    for (i = 1; i <= contagem_escala; i++) {
        printf("Tamanho do vetor: %d\n\n", (tamanho*i));
        tempo_medio = 0;

        for (j = 0; j < contagem_execucoes; j++) {
            for (k = 0; k < (tamanho*i); k++) {
                vetor[k] = rand() % 101;
            }

            inicio = clock();

            mergeSort(0, (tamanho*i), vetor);

            fim = clock();

            tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo_medio += tempo_gasto;

            printf("Tempo execucao %d: %f\n", j + 1, tempo_gasto);
        }

        tempo_medio /= contagem_execucoes;

        printf("\nTempo medio: %f\n\n", tempo_medio);
    }
}
