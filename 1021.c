#include <stdio.h>

int main() {
    double valor;
    int centavos;

    scanf("%lf", &valor);

    centavos = (int)(valor * 100 + 0.5);

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", centavos / 10000);
    centavos %= 10000;

    printf("%d nota(s) de R$ 50.00\n", centavos / 5000);
    centavos %= 5000;

    printf("%d nota(s) de R$ 20.00\n", centavos / 2000);
    centavos %= 2000;

    printf("%d nota(s) de R$ 10.00\n", centavos / 1000);
    centavos %= 1000;

    printf("%d nota(s) de R$ 5.00\n", centavos / 500);
    centavos %= 500;

    printf("%d nota(s) de R$ 2.00\n", centavos / 200);
    centavos %= 200;

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", centavos / 100);
    centavos %= 100;

    printf("%d moeda(s) de R$ 0.50\n", centavos / 50);
    centavos %= 50;

    printf("%d moeda(s) de R$ 0.25\n", centavos / 25);
    centavos %= 25;

    printf("%d moeda(s) de R$ 0.10\n", centavos / 10);
    centavos %= 10;

    printf("%d moeda(s) de R$ 0.05\n", centavos / 5);
    centavos %= 5;

    printf("%d moeda(s) de R$ 0.01\n", centavos);
}
