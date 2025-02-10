#include <stdio.h>
#include <string.h>

int main() {
    int testes, i;
    char frase[51];

    scanf("%d", &testes);
    while (getchar() != '\n');

    while (testes) {
        scanf("%[^\n]", frase);
        while (getchar() != '\n');

        for (i = 0; i < (int)strlen(frase); i++) {
            if (frase[i] >= 97 && frase[i] <= 122) {
                if (i == 0 || frase[i - 1] == 32) {
                    printf("%c", frase[i]);
                }
            }
        }
        printf("\n");

        testes--;
    }
}