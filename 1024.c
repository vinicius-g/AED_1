#include <stdio.h>
#include <string.h>

int main() {
    int testes, i, tamanho;
    char frase[1001], aux[2];

    scanf("%d ", &testes);

    while (testes > 0) {
        fgets(frase, 1001, stdin);
        frase[strlen(frase) - 1] = '\0';
        tamanho = (int)strlen(frase);

        for (i = 0; i < tamanho; i++) {
            if ((frase[i] >= 65 && frase[i] <= 90) || (frase[i] >= 97 && frase[i] <= 122)) {
                frase[i] = frase[i] + 3;
            }
        }

        for (i = 0; i < tamanho/2; i++) {
            aux[0] = frase[tamanho - 1 - i];
            frase[tamanho - 1 - i] = frase[i];
            frase[i] = aux[0];
        }

        for (i = (tamanho)/2; i < tamanho; i++) {
            frase[i] = frase[i] - 1;
        }

        printf("%s\n", frase);

        testes--;
    }
}