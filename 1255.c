#include <stdio.h>
#include <string.h>

int main() {
    int testes, frequencia[26], i, max;
    char frase[201];

    scanf("%d", &testes);

    while (getchar() != '\n');

    while (testes) {
        scanf("%[^\n]", frase);
        while (getchar() != '\n');

        for (i = 0; i < 26; i++) {
            frequencia[i] = 0;
        }

        max = 0;

        for (i = 0; i < (int)strlen(frase); i++) {
            if (frase[i] >= 65 && frase[i] <= 90) {
                frequencia[frase[i] - 65]++;

                if (frequencia[frase[i] - 65] > max) {
                    max = frequencia[frase[i] - 65];
                }
            }

            if (frase[i] >= 97 && frase[i] <= 122) {
                frequencia[frase[i] - 97]++;

                if (frequencia[frase[i] - 97] > max) {
                    max = frequencia[frase[i] - 97];
                }
            }
        }

        testes--;

        for (i = 0; i < 26; i++) {
            if (frequencia[i] == max) {
                printf("%c", i + 97);
            }
        }
        printf("\n");
    }
}