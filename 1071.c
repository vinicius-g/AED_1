#include <stdio.h>

int main() {
    int a, b, soma = 0, i;

    scanf("%d %d", &a, &b);

    if (a < b) {
        for (i = a + 1; i < b; i++) {
            if (i % 2 != 0) soma += i;
        }
    } else {
        for (i = a - 1; i > b; i--) {
            if (i % 2 != 0) soma += i;
        }
    }

    printf("%d\n", soma);
}