#include <stdio.h>

int main() {
    int testes, dias;
    float comida;

    scanf("%d", &testes);

    while (testes) {
        dias = 0;
        scanf("%f", &comida);

        while (comida > 1) {
            dias++;
            comida /= 2;
        }

        printf("%d dias\n", dias);

        testes--;
    }
}