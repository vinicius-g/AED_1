#include <stdio.h>

int main() {
    int distancia;
    float gasto;

    scanf("%d %f", &distancia, &gasto);

    printf("%.3lf km/l\n", (float)distancia/gasto);
}