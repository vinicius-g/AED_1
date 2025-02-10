#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 10000

typedef struct {
    int id;
    long long tempoTotal;
} Funcionario;

int compare(const void *a, const void *b) {
    Funcionario *f1 = (Funcionario *)a;
    Funcionario *f2 = (Funcionario *)b;

    if (f1->tempoTotal != f2->tempoTotal) {
        return (f1->tempoTotal > f2->tempoTotal) - (f1->tempoTotal < f2->tempoTotal);
    }
    return f1->id - f2->id;
}

void heapify(Funcionario heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && compare(&heap[left], &heap[smallest]) < 0) {
        smallest = left;
    }
    if (right < size && compare(&heap[right], &heap[smallest]) < 0) {
        smallest = right;
    }

    if (smallest != index) {
        Funcionario temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

void push(Funcionario heap[], int *size, Funcionario f) {
    heap[(*size)++] = f;
    int i = *size - 1;

    while (i > 0 && compare(&heap[i], &heap[(i - 1) / 2]) < 0) {
        Funcionario temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

Funcionario pop(Funcionario heap[], int *size) {
    Funcionario top = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return top;
}

int main() {
    int quantCaixa, quantClientes;
    scanf("%d %d", &quantCaixa, &quantClientes);

    int velocidadeFuncionarios[quantCaixa], quantidadeItens[quantClientes];
    for (int i = 0; i < quantCaixa; i++) {
        scanf("%d", &velocidadeFuncionarios[i]);
    }
    for (int i = 0; i < quantClientes; i++) {
        scanf("%d", &quantidadeItens[i]);
    }

    Funcionario heap[MAX_HEAP_SIZE];
    int heap_size = 0;

    for (int i = 0; i < quantCaixa; i++) {
        Funcionario f = {i + 1, 0};
        push(heap, &heap_size, f);
    }

    long long total_time = 0;

    for (int i = 0; i < quantClientes; i++) {
        Funcionario f = pop(heap, &heap_size);
        f.tempoTotal += (long long)velocidadeFuncionarios[f.id - 1] * quantidadeItens[i];
        total_time = f.tempoTotal > total_time ? f.tempoTotal : total_time;
        push(heap, &heap_size, f);
    }

    printf("%lld\n", total_time);

    return 0;
}