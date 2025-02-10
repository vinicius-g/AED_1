#include <stdio.h>
#include <stdlib.h>

int main() {
    int testes, alunos, nota, i, *notas;
    double media, acimaDaMedia;

    scanf("%d", &testes);

    while (testes) {
        scanf("%d", &alunos);
        media = 0;
        acimaDaMedia = 0;
        notas = (int*)malloc(sizeof(int) * (long long unsigned int)alunos);

        for (i = 0; i < alunos; i++) {
            scanf("%d", &nota);
            notas[i] = nota;
            media += nota;
        }

        media /= (double)alunos;

        for (i = 0; i < alunos; i++) {
            if (notas[i] > media) acimaDaMedia++;
        }

        acimaDaMedia /= alunos;

        printf("%.3lf%%\n", (double)acimaDaMedia*100);

        free(notas);
        testes--;
    }
}