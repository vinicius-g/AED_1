#include <stdio.h>

int main()
{
    int t, competidores[5], i, ganhadores = 0;

    scanf("%d", &t);

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &competidores[i]);
        if (competidores[i] == t)
            ganhadores++;
    }

    printf("%d\n", ganhadores);
}