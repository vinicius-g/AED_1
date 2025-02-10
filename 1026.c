#include <stdio.h>

unsigned int somaSemCarry(unsigned int a, unsigned int b) {
    unsigned int resultado = 0, pos = 1;

    while (a > 0 || b > 0) {
        int bit1 = a % 2;
        int bit2 = b % 2;
        int soma = bit1 + bit2;

        if (soma != 2) resultado += soma * pos;

        a /= 2;
        b /= 2;
        pos *= 2;
    }

    return resultado;
}

int main() {
    unsigned int n1, n2;

    while (scanf("%u %u", &n1, &n2) != EOF) {
        printf("%u\n", somaSemCarry(n1, n2));
    }
}