#include <stdio.h>
#include <string.h>

int main() {
    char numErro, numReal[102];
    int i, j;

    scanf("%c", &numErro);
    scanf(" %s", numReal);

    while (numErro != '0') {
        for (i = 0; i < (int)strlen(numReal); i++) {
            if (numReal[i] == numErro) {
                for (j = i + 1; j < (int)strlen(numReal); j++) {
                    numReal[j - 1] = numReal[j];
                }
                numReal[j - 1] = '\0';
                i--;
            }
        }

        while (numReal[0] == '0') {
            for (j = 1; j < (int)strlen(numReal); j++) {
                    numReal[j - 1] = numReal[j];
            }
            numReal[j - 1] = '\0';
        }

        if (numReal[0] == '\0') {
            printf("0\n");
        } else {
            printf("%s\n", numReal);
        }

        scanf(" %c", &numErro);
        scanf(" %s", numReal);
    }
}