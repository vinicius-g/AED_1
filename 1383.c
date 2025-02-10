#include <stdio.h>

int verificar_linha_coluna(int, int, int, int[9][3][3]);

int verificar_quadrante(int, int, int[3][3]);

int main() {
    int sudoku[9][3][3], linha, coluna, quadrante, novo_valor, tamanho_sudoku = 0, valido = 1;

    for (quadrante = 0; quadrante < 9; quadrante++) {
        tamanho_sudoku = 0;

        for (linha = 0; linha < 3; linha++) {
            for (coluna = 0; coluna < 3; coluna++) {
                scanf("%d", &novo_valor);
                valido = verificar_quadrante(novo_valor, tamanho_sudoku, sudoku[quadrante]);

                if (!valido) {
                    break;
                }

                sudoku[quadrante][linha][coluna] = novo_valor;
                valido = verificar_linha_coluna(linha, coluna, quadrante, sudoku);

                if (!valido) {
                    break;
                }

                tamanho_sudoku++;
            }

            if (!valido) {
                break;
            }
        }

        if (!valido) {
            printf("Sudoku invalido!\n");
            break;
        }
    }

    printf("\n");

    if (valido) {
        for (linha = 0; linha < 9; linha++) {
            for (coluna = 0; coluna < 9; coluna++) {
                printf("%d ", sudoku[(coluna/3) + (linha/3 * 3)][linha - (linha/3 * 3)][coluna - (coluna/3 * 3)]);

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
}

int verificar_linha_coluna(int linha, int coluna, int quadrante, int sudoku[9][3][3]) {
    int quadrante_linha, quadrante_coluna;

    for (quadrante_linha = quadrante % 3; quadrante_linha > 0; quadrante_linha--) {
        if (sudoku[quadrante][linha][coluna] == sudoku[quadrante - quadrante_linha][linha][coluna]) {
            printf("Numeros repetidos na mesma linha!\n");
            return 0;
        }
    }

    for (quadrante_coluna = quadrante / 3; quadrante_coluna > 0; quadrante_coluna--) {
        if (sudoku[quadrante][linha][coluna] == sudoku[quadrante - (quadrante_coluna * 3)][linha][coluna]) {
            printf("Numeros repetidos na mesma coluna!\n");
            return 0;
        }
    }

    return 1;
}

int verificar_quadrante(int novo_valor, int tamanho_sudoku, int quadrante_sudoku[3][3]) {
    int contador;

    for (contador = 0; contador < tamanho_sudoku; contador++) {
        if (novo_valor == quadrante_sudoku[contador/3][contador%3]) {
            printf("Numero repetido no quadrante!\n");
            return 0;
        }
    }

    return 1;
}