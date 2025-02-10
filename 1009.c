#include <stdio.h>

int main() {
    char nome[100];
    double salario, vendas;

    scanf("%s", nome);
    while (getchar() != '\n');
    scanf("%lf %lf", &salario, &vendas);

    vendas = vendas * 15/100;

    printf("TOTAL = R$ %.2lf\n", salario + vendas);
}