#include <stdio.h>

int main() {
    int horaInicio, minutosInicio, horaFim, minutosFim, horasTotais, minutosTotais;

    scanf("%d %d %d %d", &horaInicio, &minutosInicio, &horaFim, &minutosFim);

    if (horaFim > horaInicio) {
        horasTotais = horaFim - horaInicio;
    } else if (horaFim == horaInicio) {
        if (minutosFim > minutosInicio) {
            horasTotais = 0;
        } else {
            horasTotais = 24;
        }
    } else {
        horasTotais = 24 - (horaInicio - horaFim);
    }

    if (minutosFim > minutosInicio) {
        minutosTotais = minutosFim - minutosInicio;
    } else if (minutosFim == minutosInicio) {
        minutosTotais = 0;
    } else {
        minutosTotais = 60 - (minutosInicio - minutosFim);
        horasTotais--;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horasTotais, minutosTotais);
}