#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalaVetor(int inicio, int meio, int fim, int vetor[]) {
    int contadorInicio, contadorMeio, contador, *vetor_temp;

    vetor_temp = (int*)malloc(sizeof(int) * (fim - inicio));

    contadorInicio = inicio;
    contadorMeio = meio;
    contador = 0;

    while (contadorInicio < meio && contadorMeio < fim) {
        if (vetor[contadorInicio] < vetor[contadorMeio]) {
            vetor_temp[contador++] = vetor[contadorInicio++];
        } else {
            vetor_temp[contador++] = vetor[contadorMeio++];
        }
    }

    while (contadorInicio < meio) {
        vetor_temp[contador++] = vetor[contadorInicio++];
    }

    while (contadorMeio < fim) {
        vetor_temp[contador++] = vetor[contadorMeio++];
    }

    for (contadorInicio = inicio; contadorInicio < fim; contadorInicio++) {
        vetor[contadorInicio] = vetor_temp[contadorInicio - inicio];
    }

    free(vetor_temp);
}

void mergeSort(int inicio, int fim, int vetor[]) {
    if (inicio < fim - 1) {
        int meio = (inicio + fim)/2;

        mergeSort(inicio, meio, vetor);
        mergeSort(meio, fim, vetor);
        intercalaVetor(inicio, meio, fim, vetor);
    }
}

int main() {
    const int tamanho = 50000;
    int i, j, k, contagem_execucoes = 3, contagem_escala = 8;
    int vetor[tamanho * contagem_escala];
    clock_t inicio, fim;
    double tempo_gasto = 0, tempo_medio = 0;

    srand(time(NULL));

    for (i = 1; i <= contagem_escala; i++) {
        printf("Tamanho do vetor: %d\n\n", (tamanho*i));

        for (j = 0; j < contagem_execucoes; j++) {
            for (k = 0; k < (tamanho*i); k++) {
                vetor[k] = rand() % 101;
            }

            inicio = clock();

            mergeSort(0, (tamanho*i), vetor);

            fim = clock();

            tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempo_medio += tempo_gasto;

            printf("Tempo execucao %d: %f\n\n", j + 1, tempo_gasto);
        }

        tempo_medio /= contagem_execucoes;

        printf("Tempo medio: %f\n\n", tempo_medio);
    }
}
