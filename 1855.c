#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mapaValido(char **mapa, int altura, int largura) {
    int posx = 0, posy = 0, direcao, valido = 1;

    direcao = 1;

    while (valido) {
        if (posx >= largura || posx < 0) {
            valido = 0;
            break;
        }

        if (posy >= altura || posy < 0) {
            valido = 0;
            break;
        }

        if (mapa[posy][posx] == '*') {
            break;
        }

        if (mapa[posy][posx] == '!') {
            valido = 0;
            break;
        }

        if (mapa[posy][posx] == '.') {
            mapa[posy][posx] = '!';

            if (direcao == 1) {
                posx++;
            }
            if (direcao == 2) {
                posy++;
            }
            if (direcao == 3) {
                posx--;
            }
            if (direcao == 4) {
                posy--;
            }
        }

        if (mapa[posy][posx] == '>') {
            direcao = 1;
            posx++;
        }

        if (mapa[posy][posx] == 'v') {
            direcao = 2;
            posy++;
        }

        if (mapa[posy][posx] == '<') {
            direcao = 3;
            posx--;
        }

        if (mapa[posy][posx] == '^') {
            direcao = 4;
            posy--;
        }
    }

    return valido;
}

int main() {
    int largura, altura, i, j, valido;
    char **mapa;

    scanf("%d", &largura);
    scanf("%d", &altura);

    mapa = (char**)malloc(sizeof(char*) * altura);
    for (i = 0; i < altura; i++) {
        mapa[i] = (char*)malloc(sizeof(char) * largura);
    }

    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }

    valido = mapaValido(mapa, altura, largura);
    if (valido) {
        printf("*\n");
    } else {
        printf("!\n");
    }

    for (i = 0; i < altura; i++) {
        free(mapa[i]);
    }
    free(mapa);
}