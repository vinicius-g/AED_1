#include <stdio.h>

int mdc(int a, int b) {
    int aux;

    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}

int main() {
    int testes, f1, f2;

    scanf("%d", &testes);

    while (testes--) {
        scanf("%d %d", &f1, &f2);

        int resultado = mdc(f1, f2);

        printf("%d\n", resultado);
    }

    return 0;
}