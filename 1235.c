#include <stdio.h>
#include <string.h>

int main() {
    int testes, meio, i;
    char frase[101], aux;

    scanf("%d", &testes);

    while (getchar() != '\n');

    while (testes) {
        scanf("%[^\n]", frase);
        while (getchar() != '\n');

        meio = ((int)strlen(frase) / 2) - 1;

        for (i = meio; i > meio/2; i--) {
            aux = frase[meio - i];
            frase[meio - i] = frase[i];
            frase[i] = aux;
        }

        for (i = 0; i <= (meio + 1)/2; i++) {
            aux = frase[meio + i];
            frase[meio + i] = frase[(int)strlen(frase) - i];
            frase[(int)strlen(frase) - i] = aux;
        }

        printf("%s\n", frase);

        testes--;
    }
}