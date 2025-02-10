#include <stdio.h>

int main() {
    int id, quant;
    double valor, total = 0;

    scanf("%d %d %lf", &id, &quant, &valor);

    total += quant * valor;

    scanf("%d %d %lf", &id, &quant, &valor);

    total += quant * valor;

    printf("VALOR A PAGAR: R$ %.2lf\n", total);
}