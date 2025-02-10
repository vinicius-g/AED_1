#include <stdio.h>

int main() {
    int testes, n1, n2, encaixa;

    scanf("%d", &testes);

    while (testes) {
        scanf("%d %d", &n1, &n2);
        encaixa = 1;

        while (n2 >= 1) {
            if (n2 % 10 != n1 % 10) {
                encaixa = 0;
                break;
            }
            n2 /= 10;
            n1 /= 10;
        }

        if (encaixa) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }

        testes--;
    }
}