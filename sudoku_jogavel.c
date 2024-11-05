#include <stdio.h>

void inicializarSudoku(char sudoku[9][9]) {
    int linha, coluna;

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            sudoku[linha][coluna] = '*';
        }
    }
}

void imprimirSudoku(char sudoku[9][9]) {
    int linha, coluna;

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            printf("%c ", sudoku[linha][coluna]);

            if (coluna == 2 || coluna == 5) {
                printf("| ");
            }
        }

        printf("\n");
        if (linha == 2 || linha == 5) {
            printf("------+-------+------\n");
        }
    }
}

int verificarEntradaPosicao(int posicao) {
    if (posicao < 1 || posicao > 9) {
        return 0;
    }

    return 1;
}

int verificarNumeroRepetido(char sudoku[9][9], int linha, int coluna, char novoValor) {
    if (sudoku[linha - 1][coluna - 1] == novoValor) {
        return 0;
    }

    return 1;
}

int verificarLinha(char sudoku[9][9], int linha, char novoValor) {
    int coluna;

    for (coluna = 0; coluna < 9; coluna++) {
        if (sudoku[linha - 1][coluna] == novoValor) {
            return 0;
        }
    }

    return 1;
}

int verificarColuna(char sudoku[9][9],int coluna, char novoValor) {
    int linha;

    for (linha = 0; linha < 9; linha++) {
        if (sudoku[linha][coluna - 1] == novoValor) {
            return 0;
        }
    }

    return 1;
}

int verificarQuadrante(char sudoku[9][9], int linha, int coluna, char novoValor) {
    int contadorLinha, contadorColuna,
    inicioLinha = (linha - 1) / 3 * 3,
    inicioColuna = (coluna - 1) / 3 * 3;

    for (contadorLinha = inicioLinha; contadorLinha < inicioLinha + 3; contadorLinha++) {
        for (contadorColuna = inicioColuna; contadorColuna < inicioColuna + 3; contadorColuna++) {
            if (sudoku[contadorLinha][contadorColuna] == novoValor) {
                return 0;
            }
        }
    }

    return 1;
}

int preencherSudoku(char sudoku[9][9], int linha, int coluna, char novoValor) {
    if (!verificarNumeroRepetido(sudoku, linha, coluna, novoValor)) {
        printf("Valor: %c repetido na mesma posicao!\n", novoValor);
        printf("Selecione outro valor!\n");

        return 0;
    }

    if (!verificarLinha(sudoku, linha, novoValor)) {
        printf("Valor: %c repetido na linha: %d!\n", novoValor, linha);
        printf("Selecione outro valor!\n");

        return 0;
    }

    if (!verificarColuna(sudoku, coluna, novoValor)) {
        printf("Valor: %c repetido na linha %d!\n", novoValor, linha);
        printf("Selecione outro valor!\n");

        return 0;
    }

    if (!verificarQuadrante(sudoku, linha, coluna, novoValor)) {
        printf("Valor; %c repetido no quadrante %d!\n", novoValor, ((linha - 1) / 3 * 3 + ((coluna - 1) / 3) + 1));
        printf("Selecione outro valor!\n");

        return 0;
    }

    sudoku[linha - 1][coluna - 1] = novoValor;

    imprimirSudoku(sudoku);

    return 1;
}

int main() {
    char sudoku[9][9], novoValor;
    int linha, coluna, contadorSudoku = 0;

    inicializarSudoku(sudoku);

    imprimirSudoku(sudoku);

    printf("Considere as posicoes de linha e coluna iniciando em 1!\n");

    do {
        printf("Selecione a linha:\n");
        scanf("%d", &linha);

        if (!verificarEntradaPosicao(linha)) {
            printf("Linha: %d nao esta entre 1 e 9!\n", linha);
        } else {
            printf("Selecione a coluna:\n");
            scanf("%d", &coluna);

            if (!verificarEntradaPosicao(coluna)) {
                printf("Coluna: %d nao esta entre 1 e 9!\n", coluna);
            } else {
                printf("Selecione o numero para a posicao: \nlinha: %d e coluna: %d\n", linha, coluna);
                scanf(" %c", &novoValor);

                if (getchar() != 10 || novoValor == '0') {
                    printf("Valor nao adicionado, porque nao esta entre 1 e 9!\n");
                    while(getchar() != 10);
                } else if (preencherSudoku(sudoku, linha, coluna, novoValor)) {
                    contadorSudoku++;
                }
            }
        }
    } while (contadorSudoku < 81);

    printf("Sudoku finalizado! Parabens <3");
}