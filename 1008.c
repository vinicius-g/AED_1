#include <stdio.h>

int main() {
    int num, horas;
    double valor;

    scanf("%d %d %lf", &num, &horas, &valor);

    printf("NUMBER = %d\n", num);
    printf("SALARY = U$ %.2lf\n", horas * valor);
}