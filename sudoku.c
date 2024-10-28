#include <stdio.h>

void lerMatriz(int sudoku[9][9]) {
    int linha, coluna;

    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            scanf("%d", &sudoku[linha][coluna]);
        }
    }
}

int verificarQuadrante(int inicioLinha, int inicioColuna, int sudoku[9][9]) {
    int subSudoku[9] = {0,0,0,0,0,0,0,0,0}, linha, coluna;

    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            if (subSudoku[(sudoku[(inicioLinha + linha)][(inicioColuna + coluna)]) - 1]) {
                return 0;
            }

            subSudoku[(sudoku[(inicioLinha + linha)][(inicioColuna + coluna)]) - 1] = 1;
        }
    }

    return 1;
}

int verificarLinha(int linha, int sudoku[9][9]) {
    int linha_sudoku[9] = {0,0,0,0,0,0,0,0,0}, coluna;

    for (coluna = 0; coluna < 9; coluna++) {
        if (linha_sudoku[(sudoku[linha][coluna]) - 1]) {
            return 0;
        }

        linha_sudoku[(sudoku[linha][coluna]) - 1] = 1;
    }

    return 1;
}

int verificarColuna(int coluna, int sudoku[9][9]) {
    int coluna_sudoku[9] = {0,0,0,0,0,0,0,0,0}, linha;

    for (linha = 0; linha < 9; linha++) {
        if (coluna_sudoku[(sudoku[linha][coluna]) - 1]) {
            return 0;
        }

        coluna_sudoku[(sudoku[linha][coluna]) - 1] = 1;
    }

    return 1;
}

int verificarSudoku(int sudoku[9][9]) {
    int contador, linha, coluna;

    for (contador = 0; contador < 9; contador++) {
        if (!verificarLinha(contador, sudoku)) {
            return 0;
        }

        if (!verificarColuna(contador, sudoku)) {
            return 0;
        }
    }

    for (linha = 0; linha < 9; linha += 3) {
        for (coluna = 0; coluna < 9; coluna += 3) {
            if (!verificarQuadrante(linha, coluna, sudoku)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int quant_sudoku, contador_instancia, sudoku[9][9];

    scanf("%d", &quant_sudoku);

    for (contador_instancia = 1; contador_instancia <= quant_sudoku; contador_instancia++) {
        lerMatriz(sudoku);

        printf("Instancia %d\n", contador_instancia);

        if (verificarSudoku(sudoku)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
}