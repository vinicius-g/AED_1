#include <stdio.h>
#include <string.h>

int main() {
    int processos, i, ciclos, processosFeitos;
    char rastro[51];

    while (scanf(" %s", rastro) != EOF) {
        scanf(" %d", &processos);

        ciclos = 0;
        processosFeitos = 0;

        for (i = 0; i < (int)strlen(rastro); i++) {
            if (rastro[i] == 'R') {
                processosFeitos++;

                if (processosFeitos == processos) {
                    processosFeitos = 0;
                    ciclos++;
                }
            }

            if (rastro[i] == 'W') {
                ciclos++;
                if (processosFeitos > 0) ciclos++;
                processosFeitos = 0;
            }
        }

        if (processosFeitos > 0) ciclos++;

        printf("%d\n", ciclos);
    }
}